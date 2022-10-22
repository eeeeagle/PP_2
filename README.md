## Паралелльное программирование - Лабораторная работа №2

## Задание

Модифицировать программу из [лабораторной работы №1](https://github.com/eeeeagle/PP_1) для параллельной работы по технологии OpenMP.

## Исследование 1

Вычисления выполнялись на системе с процессором Intel Core i5-6400 с тактовой частотой 3,3 ГГц и оперативной памятью 8 Гб. Число процессов в функции с параллельными вычислениями - 10.

_Таблица 1: время (в секундах) выполнения операции умножения квадратных матриц N порядка_
|**N**   |**50**   |**100**  |**200**  |**400** |**800**|**1600**|**3200**|
|:------:|:-------:|:-------:|:-------:|:------:|:-----:|:------:|:------:|
|**100** |0.0007476|-        |        -|-       |-      |-       |-       |
|**200** |0.0009554|0.0034559|       - |-       |-      |-       |-       |
|**400** |0.0008977|0.0030097|0.011689 |-       |-      |-       |-       |
|**800** |0.0014394|0.005207 |0.0228176|0.108082|-      |-       |-       |
|**1600**|0.0025122|0.0101572|0.0468764|0.20372 |1.13825|-       |-       |
|**3200**|0.004818 |0.0208374|0.0942076|0.395889|2.57376|23.8469 |-       |
|**6400**|0.0093755|0.0392818|0.160577 |0.740861|4.87817|51.0064 |231.379 |

`N` - порядок матрицы

Так, для произведения матриц порядка 100 и 400 время, затраченное на перемножение матриц, составило _0.0030097_ секунды.

_Таблица 2: отношение операций умножения квадратных матриц N порядка с последовательными вычислениями (таблица 1 из [лабораторной работы №1](https://github.com/eeeeagle/PP_1)) к параллельным вычислениям_ 
|**N**   |**50**   |**100**  |**200**  |**400** |**800**|**1600**|**3200**|
|:------:|:-------:|:-------:|:-------:|:------:|:-----:|:------:|:------:|
|**100** |`0.60`   |-        |        -|-       |-      |-       |-       |
|**200** |`0.93`   |1.14     |       - |-       |-      |-       |-       |
|**400** |1.97     |2.49     |3.11     |-       |-      |-       |-       |
|**800** |2.49     |3.05     |3.23     |3.21    |-      |-       |-       |
|**1600**|2.93     |3.14     |3.24     |3.80    |3.82   |-       |-       |
|**3200**|3.07     |3.26     |3.28     |3.70    |3.82   |3.89    |-       |
|**6400**|3.16     |3.26     |3.67     |3.83    |3.76   |3.86    |3.61    |

_Выделеные значения соответствуют операциям, где последовательные вычисления оказались быстрее._

Из таблицы 2 следует, что на при малых объемах вычислений, параллельные вычисления менее эффективны, однако при объемах, превышающих несколько тысяч чисел, параллельные вычисления затрачивают в несколько раз меньше времени, что особенно видно на графике 1.

_График 1: сравнение зависимости времени выполнения операции умножения матриц от объема при последовательных (синия линия) и параллельных (красная линия) вычислениях_

![cmp](https://user-images.githubusercontent.com/90867530/197345326-480e59bc-91b8-48c7-adb9-4ff07cded20c.png)

## Исследование 2

В процессе выполнения
