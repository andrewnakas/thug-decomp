/* sym: _vt$15Holder_002D3938 = 0x00367188 */

struct Inst_002D3938 {
    int m0;
    void* m4;
};

extern "C" Inst_002D3938* func_0029E710(int create);
extern "C" void func_0029E760();
extern "C" void func_002D0768(void* p);

struct Ref_002D3938 {
    int m0;
    Inst_002D3938* p;
    Ref_002D3938(Inst_002D3938* x) { p = x; }
    Inst_002D3938* Get() { return p; }
};

class Holder_002D3938 {
public:
    int m0;
    Ref_002D3938 m4;
    Holder_002D3938() : m4(func_0029E710(0)) {}
    virtual ~Holder_002D3938() { func_0029E760(); }
    virtual void Run();
    Inst_002D3938* Get() { return m4.Get(); }
};

bool Cmd_002D3938(void* params, void* script)
{
    Holder_002D3938 h;
    func_002D0768(h.Get()->m4);
    return true;
}
