<?php
// Устанавливаем заголовок ответа как JSON
header('Content-Type: application/json; charset=utf-8');

/**
 * Функция для запроса информации с SAMP сервера
 * 
 * @param string $ip IP адрес сервера
 * @param int $port Порт сервера
 * @return array|bool Массив с информацией о сервере или false при ошибке
 */
function querySampServer($ip, $port) {
    // Установка таймаута для сокета
    $socket_timeout = 1; // 1 секунда на ответ
    
    // Создаем сокет
    $socket = @fsockopen('udp://'.$ip, $port, $errno, $errstr, $socket_timeout);
    
    if (!$socket) {
        return false; // Не удалось подключиться
    }
    
    // Устанавливаем таймаут чтения для сокета
    stream_set_timeout($socket, $socket_timeout);
    
    // Формируем запрос информации о сервере (SA-MP Query "i" packet)
    $request = "SAMP";
    $request .= chr(strtok($ip, "."));
    $request .= chr(strtok("."));
    $request .= chr(strtok("."));
    $request .= chr(strtok("."));
    $request .= chr($port & 0xFF);
    $request .= chr($port >> 8 & 0xFF);
    $request .= "i";
    
    // Отправляем запрос
    fwrite($socket, $request);
    
    // Получаем ответ от сервера
    $response = fread($socket, 4096);
    
    // Закрываем соединение
    fclose($socket);
    
    // Если ответ слишком короткий, значит сервер не ответил корректно
    if (strlen($response) < 10) {
        return false;
    }
    
    // Убираем заголовок из ответа
    $response = substr($response, 11);
    
    // Разбираем ответ
    $info = array();
    
    // Получаем логическое значение passworded
    $info['passworded'] = ord($response[0]);
    
    // Получаем количество игроков
    $info['players'] = ord($response[1]);
    
    // Получаем максимальное количество игроков
    $info['maxplayers'] = ord($response[2]);
    
    // Получаем длину названия сервера
    $hostname_length = ord($response[3]);
    
    // Получаем название сервера
    $info['hostname'] = substr($response, 4, $hostname_length);
    
    // Переходим к следующему блоку данных
    $response = substr($response, 4 + $hostname_length);
    
    // Получаем длину названия игрового режима
    $gamemode_length = ord($response[0]);
    
    // Получаем название игрового режима
    $info['gamemode'] = substr($response, 1, $gamemode_length);
    
    // Успешно получили данные
    return $info;
}

// Массив с данными серверов (с фиксированными значениями онлайна)
$servers = [
    [
        "ip" => "51.75.232.71",
        "port" => "1149",
        "x2" => false,
        "name" => "HORIZON",
        "online" => 1,
        "maxOnline" => 50,
        "maintenance" => false,
        "maintenance_text" => "",
        "server_type" => "Classic",
        "server_name_color" => "#ffffff",
        "server_background_color" => "#1e88e5"
    ],
    [
        "ip" => "195.18.27.241",
        "port" => "1392",
        "x2" => true,
        "name" => "test_dh_ruloc",
        "online" => 1,
        "maxOnline" => 50,
        "maintenance" => false,
        "maintenance_text" => "",
        "server_type" => "test",
        "server_name_color" => "#ffffff",
        "server_background_color" => "#1e88e5"
    ]
];

// Включить запрос реального онлайна (true - включить, false - использовать фиксированные значения)
$use_real_online = false;

// Если включен запрос реального онлайна
if ($use_real_online) {
    // Проходим по каждому серверу и пытаемся получить реальный онлайн
    foreach ($servers as &$server) {
        // Получаем информацию о сервере через SAMP Query API
        $server_info = querySampServer($server['ip'], $server['port']);
        
        // Устанавливаем реальный онлайн, если удалось получить информацию
        if ($server_info !== false) {
            $server['online'] = $server_info['players'];
        }
        // Если не удалось получить информацию, оставляем фиксированное значение
    }
    unset($server); // Разрываем ссылку на последний элемент
}

// Создаем структуру ответа
$response = ["servers" => $servers];

// Выводим JSON
echo json_encode($response, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT);
?> 