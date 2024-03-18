// https://leetcode.com/problems/powx-n/
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

double myPow(double x, int n)
{
    double m;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        n = ((unsigned int)n) * -1;
        if (n % 2 == 0)
        {
            m = 1.0 / myPow(x, n / 2);
            return m * m;
        }
        else
        {
            return 1.0 / (myPow(x, n));
        }
    }
    if (n % 2 == 0)
    {
        m = myPow(x, n / 2);
        return m * m;
    }
    else
    {
        return (x * myPow(x, n - 1));
    }
}

void main()
{
    myPow(0.00001, 2147483647);
}