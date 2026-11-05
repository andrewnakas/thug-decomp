extern "C" int func_00225E18();

int Align_00225E68(int x)
{
    int a = func_00225E18();
    if (x % a) {
        return x / a * a + a;
    }
    return x;
}
