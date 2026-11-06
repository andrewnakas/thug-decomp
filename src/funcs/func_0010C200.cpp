/* sym: _$_13Base_0010C200 = 0x0010BFE8 */
/* sym: _vt$12Blk_0010C200 = 0x0035B510 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Base_0010C200 {
    int m0;
    void* m4;
    int m8[4];
    virtual ~Base_0010C200();
};

struct Blk_0010C200 : Base_0010C200 {
    virtual void Update();
    virtual ~Blk_0010C200();
};

Blk_0010C200::~Blk_0010C200()
{
    if (m4) func_0010A8D8(D_00388A70, m4);
}
