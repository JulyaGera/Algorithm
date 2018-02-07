# Algorithm
Оптимальное бинарное дерево поиска
 

Рассмотрим множество S = {e1, e2, …, en}, состоящее из n различных элементов таких, что e1 < e2 < … < en. Рассмотрим бинарное дерево поиска, состоящее из элементов S. Чем чаще производится запрос к элементу, тем ближе он должен располагаться к корню.

Стоимостью cost доступа к элементу ei из S в дереве будем называть значение cost(ei), равное числу ребер на пути, который соединяет корень с вершиной, содержащей элемент. Имея частоту запросов к элементам из  S, (f(e1), f(e2), ..., f(en)), определим общую стоимость дерева следующим образом:

f(e1) * cost(e1) + f(e2) * cost(e2) + … + f(en) * cost(en)

Дерево, имеющее наименьшую стоимость, считается наилучшим для поиска элементов из S. Именно поэтому оно называется Оптимальным Бинарным Деревом Поиска.

 

Вход. Состоит из нескольких тестов, каждый из которых расположен в отдельной строке. Первое число в строке n (1 ≤ n ≤ 250) указывает на размер множества S. Следующие n неотрицательных целых чисел описывают частоты запросов элементов из S: f(e1), f(e2), ..., f(en). Известно, что 0 ≤ f(ei) ≤ 100.

 

Выход. Для каждого теста в отдельной строке вывести стоимость Оптимального Бинарного Дерева Поиска.

 

Пример входа

1 5

3 10 10 10

3 5 10 20

6 1 3 5 10 20 30
Пример выхода

0

20

20

63

 

 

РЕШЕНИЕ
динамическое программирование

 

Анализ алгоритма
Пусть Ti,j равно стоимости оптимального бинарного дерева поиска, которое можно построить из элементов ei, ei+1, …, ej. Очевидно, что Ti,i = 0 (стоимость дерева поиска из одной вершины равно нулю). Для i < j имеет место рекуррентность:





 

Элемент ek ставим в корне. Стоимость построения левого поддерева равна , правого . При этом поскольку корень левого поддерева находится на один уровень ниже ek, то для учета стоимости левого поддерева необходимо добавить сумму частот всех его элементов, то есть значение . Аналогично при подсчете стоимости правого поддерева следует прибавить .

При i > j положим Ti,j = 0.

Отметим также, что решение задачи про оптимальное бинарное дерево поиска аналогично решению задачи про оптимальное умножение матриц.

 

Пример

Рассмотрим множество S, в котором имеются три элемента e1 < e2 < e3 с частотами 3, 1 и 7.  Частоты элементов могут следовать в произвольном порядке. Возможными деревьями поиска будут:
3                    3                   1                  7
  \                   \               /    \                 \
    1                  7             3      7                 3
     \                  \                                      \
       7                 1                                      1
       
 1+2*7=15            7+2*1=9          3+7=10               3+2*1=5    
стоимости деревьев

 

На рисунках изображены не все возможные деревья, но отметим, что правое крайнее дерево будет оптимальным, его стоимость наименьшая среди всех возможных и равна 5.

 

Рассмотрим четвертый тест. Искомое оптимальное бинарное дерево поиска имеет вид:
         20
        /  \
      10    30
     /
    5
   / 
  3
 /
1
Стоимость левого поддерева (если бы 10 было корнем): T1,4 = 14.

Стоимость правого поддерева (если бы 30 было корнем): T6,6 = 0.

Тогда



Если при k = 5 достигается указанный минимум, то

 = (1 + 3 + 5 + 10) + 14 + (30) + 0 = 63,

что равно стоимости всего дерева.
