/* fuzzy: 68.0 */
extern unsigned char D_00393EE0[4];
extern unsigned char D_00393EE8[4];
extern unsigned char D_00393EF0[4];
extern int D_00389F34;
extern int D_00389F38;
extern int D_00389F3C;
extern int D_00389F40;
extern int D_00389F44;
extern int D_00389F48;
extern int D_0034EBA0[4];
extern int D_0034EBB0[4];
extern int D_0034EBC0[4];
extern float D_0038BB14;
extern float D_0038BB18;
extern float D_0038BB1C;
extern float D_0038BB20;
extern float D_0038BB24;
extern float D_0038BB28;

extern "C" void func_0014BF48()
{
    int c0 = D_00393EE0[0];
    int c1 = D_00393EE0[1];
    int c2 = D_00393EE0[2];
    int c3 = D_00393EE0[3];
    int e0 = D_00393EE8[0];
    int e1 = D_00393EE8[1];
    int e2 = D_00393EE8[2];
    int e3 = D_00393EE8[3];
    D_0038BB14 = D_00389F34;
    D_0038BB18 = D_00389F38;
    D_0038BB1C = D_00389F3C;
    D_0038BB20 = D_00389F40;
    D_0038BB24 = D_00389F44;
    D_0038BB28 = D_00389F48;
    D_0034EBA0[0] = c0;
    D_0034EBA0[1] = c1;
    D_0034EBA0[2] = c2;
    D_0034EBA0[3] = c3;
    D_0034EBB0[0] = e0 - c0;
    D_0034EBB0[1] = e1 - c1;
    D_0034EBB0[2] = e2 - c2;
    D_0034EBB0[3] = e3 - c3;
    D_0034EBC0[0] = D_00393EF0[0];
    D_0034EBC0[1] = D_00393EF0[1];
    D_0034EBC0[2] = D_00393EF0[2];
    D_0034EBC0[3] = D_00393EF0[3];
}
