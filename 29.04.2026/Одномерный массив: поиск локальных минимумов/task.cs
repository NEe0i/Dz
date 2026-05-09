using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Random rnd = new Random();
        int[] numbers = new int[10];

        for (int i = 0; i < numbers.Length; i++)
            numbers[i] = rnd.Next(1, 11);

        Console.WriteLine("Массив: " + string.Join(", ", numbers));
        Console.Write("Локальные минимумы: ");

        for (int i = 0; i < numbers.Length; i++)
        {
            bool isLocalMinimum = false;

            if (i == 0)
            {
                if (numbers[i] < numbers[i + 1]) isLocalMinimum = true;
            }
            else if (i == numbers.Length - 1)
            {
                if (numbers[i] < numbers[i - 1]) isLocalMinimum = true;
            }
            else
            {
                if (numbers[i] < numbers[i - 1] && numbers[i] < numbers[i + 1])
                    isLocalMinimum = true;
            }

            if (isLocalMinimum) Console.Write(numbers[i] + " ");
        }
    }
}