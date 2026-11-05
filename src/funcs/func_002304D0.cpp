extern void* D_00392068;
extern void* D_0038FC78;
extern char D_0038FD28[];
extern char D_0038FD30[];
extern char D_00372F28[];

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_002A6070(void* p);
extern "C" void* func_002A6078(void* p);
extern "C" void* func_0022E058(void* p);

extern "C" void* func_002304D0(unsigned int crc)
{
    if (crc == func_001F0D78(D_0038FD28))
        return func_002A6070(D_00392068);
    if (crc == func_001F0D78(D_0038FD30))
        return func_002A6078(D_00392068);
    if (crc == func_001F0D78(D_00372F28))
        return func_0022E058(D_0038FC78);
    return 0;
}
