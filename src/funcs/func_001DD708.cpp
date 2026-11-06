extern "C" int func_001E21C0(int i);

extern "C" int func_001DD708()
{
    int count = 0;
    for (int i = 0; i < 42; i++) {
        if (func_001E21C0(i))
            count++;
    }
    return count;
}
