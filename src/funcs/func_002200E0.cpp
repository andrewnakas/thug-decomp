struct Game_002200E0 {
    char pad0[0x394];
    void* m394;
};
extern Game_002200E0* D_0038FC78;
extern "C" int func_00252188(void* p);

int Call_002200E0()
{
    return func_00252188(D_0038FC78->m394);
}
