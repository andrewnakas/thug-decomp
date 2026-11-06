/* fuzzy: 97.0 */
extern int D_0038E31C;
extern long D_00394120;
extern int D_0038882C;
extern int D_00388830;
extern int D_0038E318;
extern char* D_0038E320;
struct Heap_001E4000 { char pad[0xD8]; int mD8; };
extern Heap_001E4000* D_00388A70;
struct RA_001E4000 { unsigned long b0 : 1; unsigned long b1 : 1; unsigned long rest : 62; };
struct RB_001E4000 { unsigned long f0 : 9; unsigned long rest : 55; };
struct RC_001E4000 { unsigned long lo : 44; unsigned long f44 : 11; unsigned long hi : 9; };
struct Env_001E4000 {
    unsigned long r0;
    RA_001E4000 r8;
    RB_001E4000 r10;
    RC_001E4000 r18;
    unsigned long r20[2];
    RA_001E4000 r30;
    RB_001E4000 r38;
    RC_001E4000 r40;
    unsigned long r48[3];
    RB_001E4000 r60;
    unsigned long r68;
    RB_001E4000 r70;
    unsigned long r78[27];
    RB_001E4000 r150;
    unsigned long r158;
    RB_001E4000 r160;
};
extern Env_001E4000 D_003F2F40;

extern "C" long func_0010FA80();
extern "C" unsigned long func_0010FA98();
extern "C" void func_001DEEE0();
extern "C" void func_001DEF18(int);
extern "C" void func_001742A8();
extern "C" void func_001F71C0(int, int, int, int, int);
extern "C" int func_001E3FC0();
extern "C" int func_0031BB90();
extern "C" int func_0031BB30(int, int);
extern "C" void func_0010A950(Heap_001E4000*, int);
extern "C" char* func_0010BDE0(int);
extern "C" int func_001686B0(int);
extern "C" void func_0010A9B0(Heap_001E4000*);
extern "C" void func_00331238();
extern "C" void func_0031B490(int);
extern "C" void func_001651F8(int, int, int, int);
extern "C" void func_00344E68(unsigned long*, int, int, unsigned int, int, int, int);
extern "C" void func_0031BF20(int);
extern "C" void func_001E3370();
extern "C" int func_001E3C08();
extern "C" int func_001E3C58(int);
extern "C" void func_001E4398(int);
extern "C" void func_0031AF08(int, int, int, int);
extern "C" void func_0010BEB8(char*);
extern "C" void func_00168700(int);
extern "C" void func_0010FB08();

void func_001E4000(int arg)
{
    if (D_0038E31C && D_00394120 == func_0010FA80())
        return;
    func_001DEEE0();
    func_001DEF18(-1);
    func_001742A8();
    unsigned int width;
    unsigned int height;
    if (!D_0038882C) {
        width = 0x280;
        height = 0x200;
    } else {
        width = 0x280;
        height = 0x1E0;
    }
    if (!D_0038882C)
        func_001F71C0(0, 0, 0, 0x280, (int)(height * width) / 0x140);
    else
        func_001F71C0(0, 0, 0, 0x280, height * 2);
    int saved = func_001E3FC0();
    func_0031BB30(func_0031BB90(), 1);
    D_0038E318 = 1;
    func_0010A950(D_00388A70, D_00388A70->mD8);
    char* mem = func_0010BDE0(0x673760);
    if (!mem)
        return;
    D_0038E320 = mem + (0x40 - ((int)mem & 0x3F));
    unsigned int half = height >> 1;
    int heap = func_001686B0(1);
    func_0010A9B0(D_00388A70);
    func_00331238();
    func_0031B490(1);
    func_001651F8(1, 1, 0, 0);
    func_00344E68((unsigned long*)&D_003F2F40, 0, width, half, 0, 0, 1);
    int zbp = ((((int)half + 31) / 32) * 10) << 1;
    D_003F2F40.r8.b1 = 1;
    D_003F2F40.r30.b1 = 1;
    D_003F2F40.r10.f0 = 0;
    D_003F2F40.r38.f0 = zbp >> 1;
    D_003F2F40.r18.f44 = height - 1;
    D_003F2F40.r40.f44 = height - 1;
    D_003F2F40.r60.f0 = zbp >> 1;
    D_003F2F40.r150.f0 = 0;
    D_003F2F40.r70.f0 = zbp;
    D_003F2F40.r160.f0 = zbp;
    func_0031BF20(0);
    unsigned int end = (int)func_0010FA98() + D_00388830 * 5;
    while (func_0010FA98() < end) {
        func_001E3370();
        if (func_001E3C08() == 1) {
            int ok = 1;
            for (int i = 0; i < 3; i++) {
                if (func_001E3C58(i) != 1)
                    ok = 0;
            }
            if (ok)
                break;
        }
    }
    func_001E4398(arg);
    func_001F71C0(0, 0, 0, 0x280, height);
    func_0031AF08(1, 0x80F0, 0, 1);
    func_0010BEB8(mem);
    D_0038E320 = 0;
    if (heap)
        func_00168700(1);
    func_0031BB30(func_0031BB90(), saved);
    func_0010FB08();
}
