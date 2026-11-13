/* fuzzy: 95.8 */
/* blocked: game adds this before the 0x90 offset ((count*4 + this) + 0x90 at 0x0010A97C); index, pointer,
   commuted, nested-struct, unsigned and plain-array forms all give (count*4 + 0x90) + this (address fold tie). */
struct Lock_0010A950;
extern Lock_0010A950* D_00393EB0;
extern "C" void func_0010A3D0(Lock_0010A950* lock);
extern "C" void func_0010A3F8(Lock_0010A950* lock);

struct Entry_0010A950 {
    unsigned int m0;
};

struct Stack_0010A950 {
    char pad[0x8C];
    Entry_0010A950* m_top;
    Entry_0010A950 m_items[16];
    int m_count;
    void Push(unsigned int v);
};

void Stack_0010A950::Push(unsigned int v)
{
    func_0010A3D0(D_00393EB0);
    m_top = m_items + m_count;
    m_top->m0 = v;
    m_count++;
    func_0010A3F8(D_00393EB0);
}
