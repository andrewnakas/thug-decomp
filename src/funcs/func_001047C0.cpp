extern "C" void* func_003315B8(void* dst, int c, unsigned int n);

void* Clear_001047C0(unsigned int size, void* p)
{
    if (p)
        func_003315B8(p, 0, size);
    return p;
}
