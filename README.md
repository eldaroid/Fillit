# Fillit

## Обзор проекта

![alt text](https://github.com/eldaroid/pictures/blob/master/fillit/fillit.png)

Fillit - это последний обязательный для всех алгоритмический проект в школе программирования от Сбербанка, после которого необходимо выбрать направление обучение (Unix, Алгоритмы, Графика, Web). 

Цель проекта заключается в создании программы, котора могла бы расположить набор от 1 до 26 тетрамино в наименьшем возможном квадрате и распечатать результат. Написан на языке C. 
Этот проект был завершен вместе с [Yuriy Nosov](https://github.com/hthunder) 10го декабря 2019 года и оценен на 100 баллов. Задание: [`fillit.en.pdf`](https://github.com/eldaroid/fillit/blob/master/resources/fillit.en.pdf)

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

* Проверяет наличиет только допустимых символов ('.', '#').
* Проверяет на правильность размеров одного квадрата (4x4) (в конце обязательно должен стоять '\n')
* 
* 
* 
