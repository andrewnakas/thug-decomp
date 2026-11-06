/* fuzzy: 64.2 */
extern "C" unsigned long func_0010FA80();
extern volatile unsigned int D_0038E1F8[2];
extern int D_00394338[2];

int func_001E2338(int i)
{
    while (D_0038E1F8[i] != func_0010FA80()) {
    }
    return D_00394338[i];
}
