using System;
class Program
{
    static void Main()
    {
        Console.Write("Введите размер матрицы N: ");
        if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0) return;

        int[,] matrix = new int[n, n];
        Random rand = new Random();
        int sum = 0;

        Console.WriteLine("Матрица:");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i, j] = rand.Next(1, 11);
                Console.Write(matrix[i, j] + "\t");
            }
            Console.WriteLine();
        }

        for (int i = 0; i < n; i++)
        {
            sum += matrix[i, n - 1 - i];
        }

        Console.WriteLine($"Сумма элементов побочной диагонали: {sum}");
    }
}
