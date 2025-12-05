<?php
// Устанавливаем заголовок ответа как JSON
header('Content-Type: application/json; charset=utf-8');

// Массив с данными новостей
$news = [
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/start_dev.jpg",
        "title" => "Начало разработки",
        "button" => "Подробнее",
        "link" => "https://forum.brp.ru/start-development"
    ],
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/final_stage.jpg",
        "title" => "Мы на финишной прямой!",
        "button" => "Узнать больше",
        "link" => "https://forum.brp.ru/final-stage"
    ],
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/update1.jpg",
        "title" => "Обновление 1.5",
        "button" => "Подробнее",
        "link" => "https://forum.brp.ru/update-1.5"
    ],
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/event.jpg",
        "title" => "Игровое событие",
        "button" => "Участвовать",
        "link" => "https://forum.brp.ru/event"
    ],
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/jobs.jpg",
        "title" => "Новые рабочие места",
        "button" => "Узнать больше",
        "link" => "https://forum.brp.ru/new-jobs"
    ],
    [
        "imageUrl" => "https://cdn.bdsrvs.run/brp/images/news/transport.jpg",
        "title" => "Новый транспорт",
        "button" => "Каталог",
        "link" => "https://forum.brp.ru/transport"
    ]
];

// Выводим JSON
echo json_encode($news, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT);
?> 