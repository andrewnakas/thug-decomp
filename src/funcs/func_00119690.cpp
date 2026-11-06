/* sym: _vt$13List_00119690 = 0x0035C718 */
struct List_00119690;
extern "C" void func_00119730(List_00119690* self);

struct List_00119690 {
    int m0;
    List_00119690* m4;
    int m8;
    List_00119690* m_next;
    List_00119690* m_prev;
    virtual void v0();
    List_00119690();
};

List_00119690::List_00119690()
{
    m4 = this;
    m8 = 0;
    m_next = this;
    m_prev = this;
    func_00119730(this);
}
