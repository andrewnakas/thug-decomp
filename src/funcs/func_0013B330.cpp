struct Vp_0013B330 {
    char pad[0x18];
    void* m_obj;
};

extern int D_00394264;
extern void* D_0038A0E4;
extern int D_0038A0E8;
extern const int D_0035E120[];
extern char D_0035E138[][16];
extern char D_0035E198[];
extern "C" Vp_0013B330* func_0013AF50(int i);
extern "C" float func_001E5370(char* name, int flag);
extern "C" void func_00114D28(void* p, float f);

void func_0013B330(int mode)
{
    D_00394264 = mode;
    D_0038A0E4 = D_0035E138[mode];
    D_0038A0E8 = D_0035E120[mode];
    for (int i = 0; i < D_0035E120[mode]; i++) {
        void* obj = func_0013AF50(i)->m_obj;
        if (obj) {
            switch (mode) {
            case 1:
                func_00114D28(obj, func_001E5370(D_0035E198, 0) * 0.5f);
                break;
            case 2:
                func_00114D28(obj, func_001E5370(D_0035E198, 0));
                break;
            default:
                func_00114D28(obj, func_001E5370(D_0035E198, 0));
                break;
            }
        }
    }
}
