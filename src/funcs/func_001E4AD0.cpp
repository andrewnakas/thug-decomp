extern char* D_0038E320;
extern int D_00394110;
extern int D_00394114;
extern int D_0038881C;
extern "C" void func_0031BAF0(int);
extern "C" void func_0031BAB0(int);
extern "C" int func_0031C338(int);
extern "C" int func_0031B9D0(int, int);
extern "C" int func_0031C268(int);
extern "C" int func_0031B9A0(int, int);
extern "C" int func_0031C2D0(int);
extern "C" void func_001F6D90(void*);
extern "C" void func_001F5090(void*);
extern "C" int func_001F5388(void*);
extern "C" int func_001F7B70(void*);
extern "C" int func_001F6CF8(void*);
extern "C" void func_00174208();
extern "C" void func_00110DC0();

void func_001E4AD0()
{
    func_0031BAF0(D_00394110);
    func_0031BAB0(D_00394110);
    func_0031BAF0(D_00394114);
    func_0031BAB0(D_00394114);
    func_0031C338(2);
    func_0031B9D0(2, *(int*)(D_0038E320 + 0x673670));
    func_0031C268(2);
    func_0031B9A0(2, *(int*)(D_0038E320 + 0x673674));
    func_0031C2D0(2);
    func_001F6D90(D_0038E320 + 0x623540);
    func_001F5090(D_0038E320 + 0x673700);
    func_001F5388(D_0038E320 + 0x6735C0);
    func_001F7B70(D_0038E320 + 0x673680);
    func_001F6CF8(D_0038E320 + 0x673580);
    func_00174208();
    if (D_0038881C)
        func_00110DC0();
}
