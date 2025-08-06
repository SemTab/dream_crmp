package com.dmob.cr.gui;

import android.app.Dialog;
import android.content.Context;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.media.AudioAttributes;
import android.media.MediaPlayer;
import android.os.Handler;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MusicPlayer {
    private static final String TAG = "MusicPlayer";
    
    // Статический экземпляр для использования в приложении
    private static MusicPlayer instance;
    
    private Context context;
    private Dialog dialog;
    private List<Track> tracks;
    private TrackAdapter adapter;
    private int currentTrackPosition = -1;
    private boolean isPlaying = false;
    private Handler handler = new Handler();
    private MediaPlayer mediaPlayer;
    
    // UI элементы
    private ImageButton playPauseButton;
    private ImageButton prevButton;
    private ImageButton nextButton;
    private SeekBar musicSeekBar;
    private TextView currentTimeText;
    private TextView totalTimeText;
    private TextView currentTrackTitle;
    private TextView currentTrackArtist;
    private ImageView coverArt;
    
    // Конструктор
    public MusicPlayer(Context context) {
        this.context = context;
        tracks = new ArrayList<>();
        loadTracks();
        initMediaPlayer();
    }
    
    // Инициализация MediaPlayer
    private void initMediaPlayer() {
        if (mediaPlayer == null) {
            mediaPlayer = new MediaPlayer();
            mediaPlayer.setAudioAttributes(
                new AudioAttributes.Builder()
                    .setContentType(AudioAttributes.CONTENT_TYPE_MUSIC)
                    .setUsage(AudioAttributes.USAGE_MEDIA)
                    .build()
            );
            
            // Обработка окончания трека
            mediaPlayer.setOnCompletionListener(mp -> playNext());
            
            // Обработка ошибок
            mediaPlayer.setOnErrorListener((mp, what, extra) -> {
                Toast.makeText(context, "Ошибка воспроизведения", Toast.LENGTH_SHORT).show();
                return false;
            });
        }
    }
    
    // Показать диалог плеера
    public void show() {
        // Вместо создания диалога используем существующий контейнер в layout
        View musicPlayerContainer = ((android.app.Activity)context).findViewById(com.dmob.cr.R.id.music_player_container);
        if (musicPlayerContainer != null) {
            musicPlayerContainer.setVisibility(View.VISIBLE);
        
        // Установка адаптера для списка треков
            RecyclerView rvPlaylist = musicPlayerContainer.findViewById(com.dmob.cr.R.id.rvPlaylist);
        adapter = new TrackAdapter(tracks);
        rvPlaylist.setLayoutManager(new LinearLayoutManager(context));
        rvPlaylist.setAdapter(adapter);
        
            // Инициализация UI элементов
            initUIWithContainer(musicPlayerContainer);
            
            // Обновляем состояние UI в соответствии с текущим воспроизведением
            if (currentTrackPosition != -1) {
                updateTrackInfo();
                
                // Обновляем кнопку воспроизведения/паузы
                if (isPlaying && playPauseButton != null) {
                    playPauseButton.setImageResource(com.dmob.cr.R.drawable.ic_pause_music);
                    
                    // Обновляем позицию SeekBar если воспроизведение идёт
                    if (mediaPlayer != null && mediaPlayer.isPlaying()) {
                        int currentPosition = mediaPlayer.getCurrentPosition() / 1000;
                        musicSeekBar.setProgress(currentPosition);
                        updateCurrentTimeText(currentPosition);
                    }
                }
            }
            
            // Запускаем обновление SeekBar
            startSeekBarUpdate();
        }
    }
    
    // Инициализация UI элементов из контейнера
    private void initUIWithContainer(View container) {
        Button backButton = container.findViewById(com.dmob.cr.R.id.musicPlayerBackBtn);
        playPauseButton = container.findViewById(com.dmob.cr.R.id.playPauseButton);
        prevButton = container.findViewById(com.dmob.cr.R.id.prevButton);
        nextButton = container.findViewById(com.dmob.cr.R.id.nextButton);
        musicSeekBar = container.findViewById(com.dmob.cr.R.id.musicSeekBar);
        currentTimeText = container.findViewById(com.dmob.cr.R.id.currentTimeText);
        totalTimeText = container.findViewById(com.dmob.cr.R.id.totalTimeText);
        currentTrackTitle = container.findViewById(com.dmob.cr.R.id.currentTrackTitle);
        currentTrackArtist = container.findViewById(com.dmob.cr.R.id.currentTrackArtist);
        coverArt = container.findViewById(com.dmob.cr.R.id.musicPlayerCoverArt);
        Button addMusicBtn = container.findViewById(com.dmob.cr.R.id.addMusicBtn);
        
        // Установка обработчиков нажатий
        backButton.setOnClickListener(v -> dismiss());
        
        playPauseButton.setOnClickListener(v -> togglePlayPause());
        
        prevButton.setOnClickListener(v -> playPrevious());
        
        nextButton.setOnClickListener(v -> playNext());
        
        addMusicBtn.setOnClickListener(v -> showAddMusicDialog());
        
        // Настройка SeekBar
        musicSeekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (fromUser) {
                    // Установить позицию воспроизведения
                    updateCurrentTimeText(progress);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                // Ничего не делаем
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // Устанавливаем новую позицию воспроизведения
                int progress = seekBar.getProgress();
                if (mediaPlayer != null && mediaPlayer.isPlaying()) {
                    mediaPlayer.seekTo(progress * 1000); // Конвертируем секунды в миллисекунды
                }
            }
        });
        
        // Если есть треки, выбрать первый
        if (!tracks.isEmpty()) {
            selectTrack(0);
        }
    }
    
    // Инициализация UI элементов (для обратной совместимости)
    private void initUI() {
        View musicPlayerContainer = ((android.app.Activity)context).findViewById(com.dmob.cr.R.id.music_player_container);
        if (musicPlayerContainer != null) {
            initUIWithContainer(musicPlayerContainer);
        }
    }
    
    // Показать диалог добавления музыки по ссылке
    private void showAddMusicDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("Добавить музыку по ссылке");
        
        final EditText input = new EditText(context);
        input.setInputType(InputType.TYPE_CLASS_TEXT);
        input.setHint("Введите URL музыкального файла");
        builder.setView(input);
        
        builder.setPositiveButton("Добавить", (dialogInterface, which) -> {
            String url = input.getText().toString().trim();
            if (!url.isEmpty()) {
                // Добавляем трек по ссылке
                addTrackFromUrl(url);
            }
        });
        
        builder.setNegativeButton("Отмена", (dialogInterface, which) -> dialogInterface.cancel());
        
        builder.show();
    }
    
    // Добавить трек по ссылке
    private void addTrackFromUrl(String url) {
        // Проверяем URL
        if (!url.startsWith("http://") && !url.startsWith("https://")) {
            Toast.makeText(context, "Неверный формат URL", Toast.LENGTH_SHORT).show();
            return;
        }
        
        // Извлекаем имя файла из URL
        String title = url.substring(url.lastIndexOf('/') + 1);
        // Для упрощения используем название файла в качестве имени трека
        if (title.contains("?")) {
            title = title.substring(0, title.indexOf('?'));
        }
        if (title.contains(".")) {
            title = title.substring(0, title.lastIndexOf('.'));
        }
        
        // Добавляем трек с URL
        Track newTrack = new Track(title, "Сетевой трек", 0, url);
        tracks.add(newTrack);
        adapter.notifyDataSetChanged();
        
        // Проверяем продолжительность трека
        checkTrackDuration(tracks.size() - 1);
        
        Toast.makeText(context, "Трек добавлен: " + title, Toast.LENGTH_SHORT).show();
        
        // Если это первый трек, автоматически выбираем его
        if (tracks.size() == 1) {
            selectTrack(0);
        }
    }
    
    // Проверка продолжительности трека
    private void checkTrackDuration(int position) {
        if (position >= 0 && position < tracks.size()) {
            Track track = tracks.get(position);
            if (track.hasUrl()) {
                MediaPlayer tempPlayer = new MediaPlayer();
                try {
                    tempPlayer.setDataSource(track.getUrl());
                    tempPlayer.setOnPreparedListener(mp -> {
                        // Получаем длительность в миллисекундах и конвертируем в секунды
                        int durationInSeconds = mp.getDuration() / 1000;
                        track.setDuration(durationInSeconds);
                        tempPlayer.release();
                        
                        // Обновляем UI если трек сейчас выбран
                        if (currentTrackPosition == position) {
                            updateTrackInfo();
                        }
                        
                        // Обновляем адаптер
                        adapter.notifyDataSetChanged();
                    });
                    tempPlayer.setOnErrorListener((mp, what, extra) -> {
                        tempPlayer.release();
                        return false;
                    });
                    tempPlayer.prepareAsync();
                } catch (Exception e) {
                    tempPlayer.release();
                }
            }
        }
    }
    
    // Загрузка треков из папки с музыкой
    private void loadTracks() {
        tracks.add(new Track("Loading Music", "Brilliant RP", 0, "https://cdn.bdsrvs.run/loading.mp3"));
    }
    
    // Закрыть плеер (только интерфейс, музыка продолжает играть)
    public void dismiss() {
        View musicPlayerContainer = ((android.app.Activity)context).findViewById(com.dmob.cr.R.id.music_player_container);
        if (musicPlayerContainer != null) {
            musicPlayerContainer.setVisibility(View.GONE);
            // Не останавливаем проигрыватель, чтобы музыка продолжала играть
            
            // Убираем обновления интерфейса, но продолжаем воспроизведение
            handler.removeCallbacksAndMessages(null);
            
            // Запускаем отдельный Handler для проверки, не закончился ли трек
            startBackgroundPlaybackMonitor();
        }
    }
    
    // Полностью остановить плеер (используется при выходе из игры)
    public void shutdown() {
        // Останавливаем воспроизведение
        stopPlayer();
        
        // Удаляем все обработчики
        if (handler != null) {
            handler.removeCallbacksAndMessages(null);
        }
        
        // Скрываем интерфейс
        View musicPlayerContainer = ((android.app.Activity)context).findViewById(com.dmob.cr.R.id.music_player_container);
        if (musicPlayerContainer != null) {
            musicPlayerContainer.setVisibility(View.GONE);
        }
    }
    
    // Монитор фонового воспроизведения
    private void startBackgroundPlaybackMonitor() {
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                if (isPlaying) {
                    if (mediaPlayer != null && !mediaPlayer.isPlaying()) {
                        // Трек закончился, переходим к следующему
                        playNext();
                    }
                    
                    // Продолжаем проверку
                    new Handler().postDelayed(this, 1000);
                }
            }
        }, 1000);
    }
    
    // Переключение воспроизведения/паузы
    private void togglePlayPause() {
        if (currentTrackPosition == -1 && !tracks.isEmpty()) {
            currentTrackPosition = 0;
        }
        
        if (isPlaying) {
            // Поставить на паузу
            pausePlayback();
        } else {
            // Воспроизвести
            startPlayback();
        }
        
        // Обновить UI
        updateTrackInfo();
    }
    
    // Начать воспроизведение
    private void startPlayback() {
        if (currentTrackPosition == -1) return;
        
        Track track = tracks.get(currentTrackPosition);
        
        try {
            // Если уже играет, останавливаем
            if (mediaPlayer.isPlaying()) {
                mediaPlayer.stop();
            }
            
            mediaPlayer.reset();
            
            // Проверяем наличие URL
            if (track.hasUrl()) {
                // Воспроизведение по URL
                mediaPlayer.setDataSource(track.getUrl());
                mediaPlayer.prepareAsync();
                
                mediaPlayer.setOnPreparedListener(mp -> {
                    mp.start();
                    isPlaying = true;
                    playPauseButton.setImageResource(com.dmob.cr.R.drawable.ic_pause_music);
                    
                    // Обновляем длительность, если она была 0
                    if (track.getDuration() == 0) {
                        track.setDuration(mp.getDuration() / 1000);
                        updateTrackInfo();
                    }
                });
            } else {
                // Здесь будет локальное воспроизведение
                // Пока просто имитируем
                isPlaying = true;
                playPauseButton.setImageResource(com.dmob.cr.R.drawable.ic_pause_music);
            }
        } catch (IOException e) {
            Toast.makeText(context, "Ошибка воспроизведения: " + e.getMessage(), Toast.LENGTH_SHORT).show();
            isPlaying = false;
        }
    }
    
    // Приостановить воспроизведение
    private void pausePlayback() {
        if (mediaPlayer != null && mediaPlayer.isPlaying()) {
            mediaPlayer.pause();
        }
        isPlaying = false;
        playPauseButton.setImageResource(com.dmob.cr.R.drawable.ic_play_music);
    }
    
    // Выбрать трек для воспроизведения
    private void selectTrack(int position) {
        if (position >= 0 && position < tracks.size()) {
            // Если сейчас играет, останавливаем
            if (isPlaying) {
                pausePlayback();
            }
            
            currentTrackPosition = position;
            updateTrackInfo();
            
            // Уведомить адаптер о смене текущего трека только если он инициализирован
            if (adapter != null) {
            adapter.notifyDataSetChanged();
            }
        }
    }
    
    // Воспроизвести предыдущий трек
    private void playPrevious() {
        if (currentTrackPosition > 0) {
            selectTrack(currentTrackPosition - 1);
            if (isPlaying) {
                startPlayback();
            }
        }
    }
    
    // Воспроизвести следующий трек
    private void playNext() {
        if (tracks.isEmpty()) {
            return;
        }
        
        if (currentTrackPosition < tracks.size() - 1) {
            selectTrack(currentTrackPosition + 1);
            if (isPlaying) {
                startPlayback();
            }
        } else {
            // Достигнут конец списка, переходим к первому треку (цикличное воспроизведение)
            selectTrack(0);
            if (isPlaying) {
                startPlayback();
            }
        }
    }
    
    // Обновить информацию о треке
    private void updateTrackInfo() {
        if (currentTrackPosition != -1) {
            Track track = tracks.get(currentTrackPosition);
            currentTrackTitle.setText(track.getTitle());
            currentTrackArtist.setText(track.getArtist());
            
            // Обновить время
            totalTimeText.setText(formatTime(track.getDuration()));
            
            // Настройка SeekBar
            musicSeekBar.setMax(track.getDuration());
            musicSeekBar.setProgress(0);
            updateCurrentTimeText(0);
        }
    }
    
    // Форматирование времени в min:sec
    private String formatTime(int seconds) {
        int minutes = seconds / 60;
        int remainingSeconds = seconds % 60;
        return String.format("%d:%02d", minutes, remainingSeconds);
    }
    
    // Обновление текущего времени
    private void updateCurrentTimeText(int seconds) {
        currentTimeText.setText(formatTime(seconds));
    }
    
    // Запустить обновление SeekBar
    private void startSeekBarUpdate() {
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                if (isPlaying) {
                    if (mediaPlayer != null && mediaPlayer.isPlaying()) {
                        // Получаем текущую позицию в миллисекундах и конвертируем в секунды
                        int currentPosition = mediaPlayer.getCurrentPosition() / 1000;
                        musicSeekBar.setProgress(currentPosition);
                        updateCurrentTimeText(currentPosition);
                    } else {
                        // Если локальное воспроизведение или имитация
                        int currentPosition = musicSeekBar.getProgress() + 1;
                        if (currentPosition <= musicSeekBar.getMax()) {
                            musicSeekBar.setProgress(currentPosition);
                            updateCurrentTimeText(currentPosition);
                        } else {
                            // Трек закончился, переходим к следующему
                            playNext();
                        }
                    }
                }
                handler.postDelayed(this, 1000);
            }
        }, 1000);
    }
    
    // Остановить проигрыватель
    private void stopPlayer() {
        isPlaying = false;
        if (mediaPlayer != null) {
            if (mediaPlayer.isPlaying()) {
                mediaPlayer.stop();
            }
            mediaPlayer.release();
            mediaPlayer = null;
        }
    }
    
    // Класс для хранения информации о треке
    public static class Track {
        private String title;
        private String artist;
        private int duration; // в секундах
        private String url; // URL для сетевых треков
        
        public Track(String title, String artist, int duration, String url) {
            this.title = title;
            this.artist = artist;
            this.duration = duration;
            this.url = url;
        }
        
        public String getTitle() {
            return title;
        }
        
        public String getArtist() {
            return artist;
        }
        
        public int getDuration() {
            return duration;
        }
        
        public void setDuration(int duration) {
            this.duration = duration;
        }
        
        public String getUrl() {
            return url;
        }
        
        public boolean hasUrl() {
            return url != null && !url.isEmpty();
        }
    }
    
    // Адаптер для списка треков
    private class TrackAdapter extends RecyclerView.Adapter<TrackAdapter.TrackViewHolder> {
        private List<Track> trackList;
        
        public TrackAdapter(List<Track> trackList) {
            this.trackList = trackList;
        }
        
        @NonNull
        @Override
        public TrackViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(com.dmob.cr.R.layout.track_item, parent, false);
            return new TrackViewHolder(view);
        }
        
        @Override
        public void onBindViewHolder(@NonNull TrackViewHolder holder, int position) {
            Track track = trackList.get(position);
            holder.title.setText(track.getTitle());
            holder.artist.setText(track.getArtist());
            holder.duration.setText(formatTime(track.getDuration()));
            
            // Если это сетевой трек, добавим индикатор
            if (track.hasUrl()) {
                holder.title.setText(track.getTitle() + " [URL]");
            }
            
            // Выделение текущего трека
            if (position == currentTrackPosition) {
                holder.itemView.setBackgroundColor(context.getResources().getColor(com.dmob.cr.R.color.colorAccent));
            } else {
                holder.itemView.setBackgroundColor(Color.parseColor("#343A40"));
            }
            
            // Обработка нажатия на трек
            holder.itemView.setOnClickListener(v -> {
                selectTrack(position);
                togglePlayPause();
            });
            
            // Опции трека
            holder.moreOptions.setOnClickListener(v -> showTrackOptions(track, position));
        }
        
        @Override
        public int getItemCount() {
            return trackList.size();
        }
        
        // Показать опции трека
        private void showTrackOptions(Track track, int position) {
            Dialog optionsDialog = new Dialog(context);
            optionsDialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
            optionsDialog.setContentView(com.dmob.cr.R.layout.dialog_music_options);
            optionsDialog.getWindow().setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            
            // Настройка заголовка
            TextView dialogTitle = optionsDialog.findViewById(com.dmob.cr.R.id.dialogTitle);
            dialogTitle.setText(track.getTitle());
            
            // Настройка опций
            View playNowOption = optionsDialog.findViewById(com.dmob.cr.R.id.playNowOption);
            View addToQueueOption = optionsDialog.findViewById(com.dmob.cr.R.id.addToQueueOption);
            View deleteTrackOption = optionsDialog.findViewById(com.dmob.cr.R.id.deleteTrackOption);
            
            playNowOption.setOnClickListener(v -> {
                selectTrack(position);
                isPlaying = false;
                togglePlayPause(); // Начать воспроизведение
                optionsDialog.dismiss();
            });
            
            addToQueueOption.setOnClickListener(v -> {
                // Добавить в очередь (можно реализовать очередь воспроизведения)
                optionsDialog.dismiss();
            });
            
            deleteTrackOption.setOnClickListener(v -> {
                // Удалить трек из списка
                tracks.remove(position);
                notifyDataSetChanged();
                
                if (currentTrackPosition == position) {
                    // Если удалили текущий трек
                    if (tracks.isEmpty()) {
                        currentTrackPosition = -1;
                        isPlaying = false;
                        updateTrackInfo();
                    } else if (currentTrackPosition >= tracks.size()) {
                        currentTrackPosition = tracks.size() - 1;
                        updateTrackInfo();
                    }
                } else if (currentTrackPosition > position) {
                    // Если удалили трек до текущего, сдвигаем указатель
                    currentTrackPosition--;
                }
                
                optionsDialog.dismiss();
            });
            
            optionsDialog.show();
        }
        
        class TrackViewHolder extends RecyclerView.ViewHolder {
            TextView title;
            TextView artist;
            TextView duration;
            ImageButton moreOptions;
            
            public TrackViewHolder(@NonNull View itemView) {
                super(itemView);
                title = itemView.findViewById(com.dmob.cr.R.id.trackTitle);
                artist = itemView.findViewById(com.dmob.cr.R.id.trackArtist);
                duration = itemView.findViewById(com.dmob.cr.R.id.trackDuration);
                moreOptions = itemView.findViewById(com.dmob.cr.R.id.trackMoreOptions);
            }
        }
    }
    
    // Статический метод для показа музыкального плеера из любого места в игре
    public static void showMusicPlayer(Context context) {
        if (instance == null) {
            instance = new MusicPlayer(context);
        } else {
            // Обновляем контекст если нужно
            instance.context = context;
        }
        instance.show();
    }
    
    // Статический метод для закрытия музыкального плеера при выходе из игры
    public static void shutdownMusicPlayer(Context context) {
        if (instance != null) {
            instance.shutdown();
            instance = null;
        }
    }
    
    @Override
    protected void finalize() throws Throwable {
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }
        super.finalize();
    }
} 