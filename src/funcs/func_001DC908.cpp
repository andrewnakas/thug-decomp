extern "C" int func_001DC820(void* o, int i);

int func_001DC908(void* o, int i)
{
    while (!func_001DC820(o, i))
        i++;
    return i;
}
