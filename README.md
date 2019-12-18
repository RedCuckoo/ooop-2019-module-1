# ooop-2019-module-1
Варіант 23. Розв'язок першого модулю предмету "Основи об'єктно орієнтованого програмування".

Завдання 1 (60% балів). Використовуючи засоби ООП, змоделювати процес навчання в університеті.
Студенти виконують завдання з різних предметів, покращуючи свої знання. Кожен студент має
список знань і поточний рівень знань для кожного з них. Кожне завдання пов’язане з одним чи
більше знаннями, а також має рівень складності та максимальну кількість балів за його виконання.
Під час виконання завдання визначається отримана кількість балів за завдання (від 0 до
максимальної), а також час виконання (в днях): ці параметри залежать від рівня складності
завдання, рівня знань студента, що виконує завдання, а також певного випадкового фактору.
Виконання завдання підвищує рівень відповідних знань студента. Студенти мають обмежену
кількість днів на виконання всіх завдань; за один день можна виконувати не більше одного
завдання. Студенти можуть мати різні стратегії виконання завдань (наприклад, починати з
найпростіших, чи найскладніших, чи тих, що мають найбільшу кількість балів, чи пов’язані з
найкращими знаннями студента). Завдання також можуть бути різних типів (результат більше
залежить від рівня складності, чи від мінімального рівня знань, чи від середнього рівня знань, чи від
випадкового фактору). Студентам не відомий тип завдань – лише складність, кількість балів та
знання.
Створити модель системи з певною кількістю студентів, знань та завдань, промоделювати її роботу
протягом певного часу, а також до досягнення заданої загальної кількості виконаних завдань.
Задається період часу та список знань. Реалізувати алгоритм створення списку студентів, які за цей
період підвищили рівень цих знань, впорядкований за сумарним зростанням рівня знань (від
більшого до меншого).

Завдання 2 (20% балів). Реалізувати функцію f(x), що повертає дійсне значення за наступними
правилами:
1. Для натуральних (цілих додатніх) чисел n, f(n) = sin(5n+123)
2. Для від’ємних цілих чисел n, f(n) = log2 |n
5 + 223|

3. Для дійсних чисел d, f(d) = d/(d+323)
4. Для текстових рядків s, f(s) = квадрат частки символів-цифр в рядку s
5. Для пари p=(a,b), f(p) = f(b)sin(523f(a))
6. Для списку v=[v1,...,vk], f(v) = max cos (vi -823)
7. Для всіх інших значень f(x) = 35.23

Завдання 3 (20% балів+бонус). Задано абстрактний базовий клас Base, два його підкласи Alpha, Beta,
і два підкласи Alpha – Red, Green. Кожен екземпляр класу Base містить порядковий номер N
(унікальний поміж всіх підкласів, починається з 1 для першого створеного екземпляру, зростає на 1
для кожного наступного екземпляру), а також вкладений екземпляр класу Base (який може бути
відсутнім). Деструктори класів змінюють глобальну змінну S: деструктор Base S:=2S+N-23,
деструктор Alpha S:=S-N, деструктор Beta S:=S+3N+23, деструктор Red S:=S+N/2, деструктор Green
S:=S-N/2-11.
1. Реалізувати відповідні класи, створити і видалити певну кількість об’єктів, вивести
остаточне значення глобальної змінної.
2. Реалізувати функцію, яка буде отримувати список об’єктів і передбачати значення
глобальної змінної після послідовного видалення всіх цих об’єктів.
3. Для заданої кількості об’єктів M (що включає як незалежні, так і вкладені об’єкти) перебрати
всі можливі комбінації об’єктів, і вивести для кожного остаточне значення змінної. Можна
вважати M<7.
