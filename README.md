# Fillit

## Обзор проекта

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/fillit.png)

Fillit - это последний обязательный для всех алгоритмический проект в школе программирования от Сбербанка, после которого необходимо выбрать направление обучение (Unix, Алгоритмы, Графика, Web). 

Цель проекта заключается в создании программы, которая могла бы расположить набор от 1 до 26 тетрамино в наименьшем возможном квадрате и распечатать результат. Написан на языке C. 
Этот проект был завершен вместе с [Yuriy Nosov](https://github.com/hthunder) 17го октября 2019 года и оценен на 100 баллов. Задание: [`fillit.en.pdf`](https://github.com/eldaroid/fillit/blob/master/resources/fillit.en.pdf)

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/100_fillit.png)

## Что делает Fillit? 

Fillit получает следующий текстовый файл карты.

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/validfile.png)

Алгоритм программы находит наименьший из возможных квадратов, в котором можно расположить части, и распечатывает квадрат следующим образом:

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/square_fillit.png)

## Как это работает?

Этот проект опирается на стандартные функции из [библиотеки, написанной ранее (libft)](https://github.com/eldaroid/libft-fgracefo).

Сначала файл читается парсером, и все части проверяются, чтобы убедиться, что они действительны.

`validfile.c`:

* Проверяет наличие только допустимых символов ('.', '#').
* Проверяет на правильность размеров одного квадрата (4x4) (в конце обязательно должен стоять '\n')
* Считает количество сиволов '#' (обязательно должно быть только 4 хештега)
* Проверяет наличие '\n' в конце файла и в конце каждого квадрата
* Проверяет на наличие смежностей всех '#' с другими (каждый хештег соединен с другим). Правильный хештег должен иметь сумму 6 или 8 (для квадрата). Каждому хештегу присваевается такое значение, сколько он имеет рядом соседних '#'. Этот метод подсчета подробно описан в [блоге Beth Nenniger](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909).

Валидные тетрамино:

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/possible%20tetramino.png)

Затем мы вызываем функцию, которая находит и сохраняет сиволы '#' и превращает их в координаты (x, y), записывая в структуру. После мы вызываем функцию `align()`, которая смещает координаты в верхний левый угол карты. Все части хранятся в связном списке. 

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/Screen%20Shot%202020-08-20%20at%207.59.38%20AM.png)

После этого, рекурсивно пытаемся подставить тетраминки в нименьший квадрат.

![alt text](https://raw.githubusercontent.com/Jemmeh/42-Fillit/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.27%20PM.png)

![alt text](https://raw.githubusercontent.com/Jemmeh/42-Fillit/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.45%20PM.png)

![alt text](https://raw.githubusercontent.com/Jemmeh/42-Fillit/master/WorkFiles/ExplainationImages/RecursiveBacktrack.png)

## Как пользоваться?

Компилируем программу с помощью команды make.

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/compile.png)

Запускаем исполняемую программу.

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/run.png)

Можно поменять `validfile.txt` и посмотреть результат cвоего теста.
