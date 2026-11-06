int func_001AA3B8(float a)
{
    a += 0.78539819f;
    if (a < 0.0f) {
        a += 6.2831855f;
    }
    return (int)(a * 0.63661977f);
}
