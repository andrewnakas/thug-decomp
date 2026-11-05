struct Game_0021FF68 {
    char pad0[0x394];
    void* m394;
};
extern Game_0021FF68* D_0038FC78;
extern "C" int func_00251330(void* p);

bool Call_0021FF68()
{
    func_00251330(D_0038FC78->m394);
    return true;
}
