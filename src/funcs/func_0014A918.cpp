/* sym: __12Snd_0014A918 = 0x0014A468 */
/* sym: Call__12Snd_0014A918i = 0x001357B8 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Snd_0014A918 {
public:
    char pad[0xC];
    Snd_0014A918();
    int Call(int a);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

Snd_0014A918* Create_0014A918(int a)
{
    Snd_0014A918* s = new Snd_0014A918;
    s->Call(a);
    return s;
}
