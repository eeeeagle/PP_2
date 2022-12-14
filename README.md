## Задание

Модифицировать программу из [лабораторной работы №1](https://github.com/eeeeagle/PP_1) для параллельной работы по технологии OpenMP.

## Исследование: сравнение производительности между последовательными и параллельными вычислениями по технологии OpenMP в зависимости от числа потоков

Вычисления выполнялись на системе с 4-х ядерным процессором Intel Core i5-6400 с тактовой частотой 3,3 ГГц и оперативной памятью 8 Гб и тактовой частотой 2133 МГц.

_Таблица 1: время (в секундах) выполнения операции умножения квадратных матриц N порядка по технологии OpenMP_
|**N**   |**2 threads** |**3 threads** |**4 threads** |
|:------:|:------------:|:------------:|:------------:|
|**50**  |0.0002084     |0.0003471     |0.0003952     |
|**100** |0.0010032     |0.0007255     |0.0010525     |
|**200** |0.0094045     |0.0064404     |0.0049929     |
|**300** |0.0335872     |0.0229505     |0.0170587     |
|**400** |0.0826448     |0.0550671     |0.0433805     |
|**500** |0.177633      |0.115375      |0.0866637     |
|**600** |0.312592      |0.2184        |0.159164      |
|**700** |0.501006      |0.334707      |0.258948      |
|**800** |0.79232       |0.542042      |0.399262      |
|**900** |2.38724       |1.57834       |1.10106       |
|**1000**|5.11958       |3.42034       |2.57056       |
|**1200**|9.13958       |6.05882       |4.58966       |
|**1400**|15.1931       |10.0856       |7.63791       |
|**1600**|23.4204       |15.578        |11.6049       |
|**1800**|34.1464       |22.687        |17.0606       |
|**2000**|45.325        |30.3343       |24.3051       |
|**2200**|63.1006       |42.5706       |32.1474       |
|**2400**|85.1354       |56.7751       |42.8435       |
|**2600**|110.525       |74.2621       |56.0433       |
|**2800**|137.233       |92.1099       |69.412        |
|**3000**|184.178       |183.613       |109.147       |
|**3400**|260.887       |176.354       |134.812       |
|**3800**|378.536       |277.819       |202.741       |
|**4200**|517.275       |349.829       |272.244       |
|**4600**|700.333       |468.682       |361.307       |
|**5000**|907.55        |615.373       |479.466       |


_Таблица 2: отношение операций умножения квадратных матриц N порядка с последовательными вычислениями (таблица 1 из [лабораторной работы №1](https://github.com/eeeeagle/PP_1)) к параллельным вычислениям по технологии OpenMP_ 
|**N**   |**2 threads** |**3 threads** |**4 threads** |
|:------:|:------------:|:------------:|:------------:|
|**50**  |1,06          |`0,64`        |`0,56`        |
|**100** |1,81          |2,50          |1,73          |
|**200** |1,95          |2,85          |3,67          |
|**300** |2,02          |2,96          |3,99          |
|**400** |1,98          |2,97          |3,77          |
|**500** |1,90          |2,93          |3,89          |
|**600** |2,03          |2,91          |3,99          |
|**700** |2,16          |3,24          |4,18          |
|**800** |2,24          |3,28          |4,45          |
|**900** |2,27          |3,43          |4,92          |
|**1000**|2,11          |3,16          |4,21          |
|**1200**|2,05          |3,09          |4,08          |
|**1400**|2,06          |3,10          |4,10          |
|**1600**|2,04          |3,06          |4,11          |
|**1800**|2,03          |3,06          |4,07          |
|**2000**|2,09          |3,12          |3,90          |
|**2200**|2,05          |3,04          |4,02          |
|**2400**|2,04          |3,05          |4,05          |
|**2600**|2,05          |3,05          |4,04          |
|**2800**|2,08          |3,10          |4,11          |
|**3000**|1,99          |2,00          |3,36          |
|**3400**|2,04          |3,02          |3,95          |
|**3800**|2,02          |2,75          |3,77          |
|**4200**|2,03          |3,00          |3,86          |
|**4600**|1,99          |2,98          |3,87          |
|**5000**|2,02          |2,99          |3,83          |

_Выделеные значения соответствуют операциям, где последовательные вычисления оказались быстрее._

Из таблицы 2 следует, что при очень малых объемах вычислений, параллельные вычисления менее эффективны, однако при объемах, превышающих несколько тысяч чисел, параллельные вычисления затрачивают в несколько раз меньше времени, что особенно видно на графике 1.

_График 1: сравнение зависимости времени выполнения операции умножения матриц от объема при последовательных (синия линия) и параллельных (красная [2 ядра], зелёная [3 ядра], желтая [4 ядра]) вычислениях_

![lab2](https://user-images.githubusercontent.com/90867530/208433791-c34bcb90-0b6f-40e1-bf1d-d97727b8131e.png)
