struct OperationTime
{
    int hours;
    int minutes;
    int seconds;
} OperationTime;

struct OperationData
{
    float temp = 0;
    float amp = 0;
    const char *pedal = "";
    int hum = 0;
    int duty = 0;
} OperationData;