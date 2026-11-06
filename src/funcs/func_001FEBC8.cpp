struct Pool_001FEBC8;
extern Pool_001FEBC8* D_00388A70;
extern "C" void* func_0010A638(Pool_001FEBC8* pool, int size, int a, int b);
extern "C" void* func_001FA918(void* p, unsigned char a, unsigned short b, int c, unsigned char d);

extern "C" void* func_001FEBC8(void* self, unsigned char a, unsigned short b, int c, unsigned char d)
{
    return func_001FA918(func_0010A638(D_00388A70, 0x14, 1, 0), a, b, c, d);
}
