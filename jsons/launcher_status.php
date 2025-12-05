<?php
// Устанавливаем заголовок ответа как JSON
header('Content-Type: application/json; charset=utf-8');

// Настройки статуса лаунчера
// enabled: true - лаунчер включен, false - отключен
// message: причина отключения (отображается только когда enabled = false)
$launcher_status = [
    "enabled" => true,
    "message" => "Проводятся технические работы. Лаунчер временно недоступен. Пожалуйста, попробуйте позже."
];

// Выводим JSON
echo json_encode($launcher_status, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT);
?> 