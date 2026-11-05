extern char D_00375BF0[];
extern "C" char* func_00104028(char* dst, const char* src);

struct Obj_00262300 {
    char m_name[4];
    Obj_00262300();
};

Obj_00262300::Obj_00262300()
{
    func_00104028(m_name, D_00375BF0);
}
