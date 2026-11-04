struct Heap_00173DF0 {
    char pad[0x11C];
    void* m11C;
};

struct Light_00173DF0 {
    Light_00173DF0* m_next;
    float m4;
    int pad8;
    int mC;
    char pad10[0x20];
    int m30;
    int m34;
    char pad38[8];
    int m40;
    int m44;
    int m48;
    Light_00173DF0* m_prev;
    int pad50;
    unsigned int m_color;
};

struct Buf_00173DF0 {
    unsigned long m_lo : 32;
    unsigned long m_hi : 32;
};

extern int D_0038BE40;
extern int D_00388818;
extern Heap_00173DF0* D_00388A70;
extern char* D_003942C4;
extern char* D_003942C8;
extern char* D_003942CC;
extern char* D_003942D0;
extern char* volatile D_003942D4;
extern int D_003942D8;
extern Buf_00173DF0* D_003942AC;
extern char* D_00394274;
extern int D_00394310;
extern Light_00173DF0* D_003942FC;
extern Light_00173DF0* D_00394300;
extern Light_00173DF0* D_00394298;
extern Light_00173DF0* D_003942A0;
extern Light_00173DF0* D_003942F4;
extern Light_00173DF0* D_003942F8;
extern int D_00393F58;
extern int D_00394304;
extern int D_00393F5C;
extern int D_00393F60;
extern char D_00347900[];
extern char D_003484E0[];
extern char D_003E0FE0[];

extern "C" void func_0031B490(int a);
extern "C" void func_00331238();
extern "C" void func_0031B308(int a);
extern "C" void func_001651F8(int a, int b, int c, int d);
extern "C" void func_00168680();
extern "C" char* func_0010BF90(int size, int align);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_001628A8();
extern "C" void func_001742D0();
extern "C" void func_00345160(int a);
extern "C" void func_0031BF20(int a);
extern "C" void func_003312D8(int a, int b);
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void func_00170578(void* p, int a);

extern "C" void func_00173DF0()
{
    if (D_0038BE40)
        return;
    D_0038BE40 = 1;
    func_0031B490(1);
    func_00331238();
    func_0031B308(1);
    func_001651F8(0, 0, 0, 0);
    func_00168680();
    D_003942C4 = func_0010BF90(0x800, 0x10);
    if (D_00388818) {
        D_003942C8 = func_0010BF90(0x14996, 0x10);
        func_0010A950(D_00388A70, D_00388A70->m11C);
        D_003942CC = func_0010BF90(0xF80C0, 0x10);
        func_0010A9B0(D_00388A70);
        D_003942D0 = D_003942CC;
        D_003942D4 = D_003942CC + 0x7C0600;
    } else {
        D_003942CC = func_0010BF90(0x14996, 0x10);
        D_003942D0 = D_003942CC;
        D_003942D4 = D_003942CC + 0xA4CB0;
    }
    D_003942D8 = 0xA4CB0;
    D_003942AC = (Buf_00173DF0*)func_0010BF90(8, 8);
    D_00394274 = D_003942C4;
    func_001628A8();
    func_001742D0();
    func_00345160(0);
    func_0031BF20(0);
    *(volatile int*)0x10009020 = 0;
    *(volatile int*)0x10009030 = D_003942AC->m_hi;
    *(volatile int*)0x10009000 = 0x145;
    func_003312D8(0, 0);
    func_001651F8(1, 0, 0, 0);
    *(volatile int*)0x10008020 = (D_003484E0 - D_00347900 + 15) / 16;
    *(volatile unsigned int*)0x10008010 = (unsigned int)D_00347900;
    *(volatile int*)0x10008000 = 0x100;
    func_003312D8(0, 0);
    D_00394310 = 0;

    D_003942FC = (Light_00173DF0*)func_0010BDE0(0x58);
    func_003315B8(D_003942FC, 0, 0x58);
    D_003942FC->m_color = 0xFFFFFF;
    D_003942FC->m30 = 0;
    D_003942FC->m34 = 0;
    D_003942FC->m44 = 0x4000;
    D_003942FC->mC = 0;
    D_003942FC->m40 = 0x3E00;
    D_003942FC->m4 = 1500.0009765625f;

    D_00394300 = (Light_00173DF0*)func_0010BDE0(0x58);
    func_003315B8(D_00394300, 0, 0x58);
    D_00394300->m4 = 9999.0f;
    D_00394300->m30 = 0;
    D_00394300->m34 = 0;
    D_00394300->m40 = 0x3000;
    D_00394300->m44 = 0x4000;
    D_00394300->mC = 0;
    D_00394300->m48 = 0;
    D_00394300->m_color = (0x30 << 16) | (0x30 << 8) | 0x30;

    D_00394298 = (Light_00173DF0*)func_0010BDE0(0x58);
    func_003315B8(D_00394298, 0, 0x58);
    D_00394298->m4 = 10000.0f;
    D_00394298->m_color = 0;
    D_00394298->m30 = 0;
    D_00394298->m34 = 0;
    D_00394298->m44 = 0x4000;
    D_00394298->mC = 0;
    D_00394298->m48 = 0;
    D_00394298->m40 = 0x3000;

    D_003942A0 = (Light_00173DF0*)func_0010BDE0(0x58);
    func_003315B8(D_003942A0, 0, 0x58);
    D_003942A0->m4 = 1000000.0f;
    D_003942A0->m44 = 0x4000;
    D_003942A0->m30 = 0;
    D_003942A0->m34 = 0;
    D_003942A0->m40 = 0;
    D_003942A0->m_color = 0x800000;

    D_003942FC->m_next = D_00394300;
    D_00394300->m_next = D_00394298;
    D_00394298->m_next = D_003942A0;
    D_003942A0->m_next = 0;
    D_003942FC->m_prev = 0;
    D_00394300->m_prev = D_003942FC;
    D_00394298->m_prev = D_00394300;
    D_003942A0->m_prev = D_00394298;
    D_003942F4 = D_003942FC;
    D_003942F8 = D_003942A0;
    D_00394304 = 0x2BC0;
    D_00393F5C = 0x2BC0;
    D_00393F58 = 0x2BC0;
    D_00393F60 = 0;
    func_00170578(D_003E0FE0, 1);
}
