/* sym: _vt$13Heap_0010C158 = 0x0035B528 */
class Heap_0010C158;
extern "C" void func_0010C020(Heap_0010C158* self, char* start, char* end);

class Heap_0010C158 {
public:
    int m0;
    char* m_start;
    int m_size;
    char* m_end;
    int m10;
    int m14;
    Heap_0010C158(char* start, char* end);
    virtual ~Heap_0010C158();
};

Heap_0010C158::Heap_0010C158(char* start, char* end)
{
    func_0010C020(this, start, end);
}
