/* fuzzy: 76.5 */
struct Req_0010E7E8 {
    int m_result;
    int m_async;
};

extern volatile int D_00388C94;
extern "C" int func_0010EFE0(Req_0010E7E8* r);
extern "C" int func_0010E830(Req_0010E7E8* r);

extern "C" void func_0010E7E8(Req_0010E7E8* r, int cmd, int result)
{
    r->m_result = result;
    D_00388C94 = 1;
    if (r->m_async) {
        func_0010EFE0(r);
    } else {
        func_0010E830(r);
    }
}
