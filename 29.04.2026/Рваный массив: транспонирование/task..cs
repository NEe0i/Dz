using System;
using System.Linq;

class Program
{
    static void Main()
    {

        double[][] source = new double[][]
        {
            new double[] { 1.1, 1.2, 1.3 },
            new double[] { 2.1 },
            new double[] { 3.1, 3.2 }
        };

        int maxCols = 0;
        foreach (var row in source)
        {
            if (row.Length > maxCols) maxCols = row.Length;
        }

        double[][] transposed = new double[maxCols][];

        for (int i = 0; i < maxCols; i++)
        {

            transposed[i] = new double[source.Length];

            for (int j = 0; j < source.Length; j++)
            {
                if (i < source[j].Length)
                {
                    transposed[i][j] = source[j][i];
                }
                else
                {
                    transposed[i][j] = 0.0;
                }
            }
        }
        foreach (var row in transposed)
        {
            Console.WriteLine(string.Join("\t", row));
        }
    }
}