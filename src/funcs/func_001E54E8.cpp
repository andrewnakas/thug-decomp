extern char D_0038E490[];
struct Obj_001E54E8 {
    char pad[0xC];
    char* mC;
};
extern "C" Obj_001E54E8* func_001E5040();

char* func_001E54E8()
{
    Obj_001E54E8* p = func_001E5040();
    if (!p)
        return D_0038E490;
    return p->mC;
}
