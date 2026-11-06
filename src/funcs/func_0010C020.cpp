class Heap_0010C020 {
public:
    int m0;
    char* m_start;
    int m_size;
    char* m_end;
    int m10;
    int m14;
    void Init(char* start, char* end);
};

void Heap_0010C020::Init(char* start, char* end)
{
    m_start = start;
    m_end = end;
    m_size = end - start;
    m14 = 0;
    m10 = 0;
}
