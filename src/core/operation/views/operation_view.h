#include <infrastructure/display.h>
#include <core/operation/icons/device.h>

class OperationView
{
private:
    Display &display;

    void valueSelector(int value)
    {
        display.drawTriangle((1 + value), 50, (25 + value), 50, (14 + value), 64); // X+29
        display.drawTriangle((14 + value), 64, (39 + value), 64, (24 + value), 50);
    }

    void valueFrame(int value)
    {
        display.drawLine((0 + (value * 29)), 48, (24 + (value * 29)), 48);
        display.drawLine((24 + (value * 29)), 48, (40 + (value * 29)), 64);
        display.drawLine((25 + (value * 29)), 48, (41 + (value * 29)), 64);
    }

    void setValueSelector(int value)
    {
        if (value == 0)
        {
            valueSelector(0);
        }
        else if (value == 1)
        {
            valueSelector(29);
        }
        else if (value == 2)
        {
            valueSelector(58);
        }
        else if (value == 3)
        {
            valueSelector(87);
        }
    }

    void setDevice(int value)
    {
        if (value == 0)
        {
            display.drawBox(115, 1, 12, 20);
        }
        else
        {
            display.drawBox(115, 25, 12, 20);
        }
    }

    void setDeviceType(int value)
    {
        if (value)
        {
            display.drawBox(1, 1, 15, 10);
        }
        else
        {
            display.drawBox(1, 1, 15, 10);
        }
        // display.render();
    }

    void setPedalType(int value)
    {
        if (value == 0)
        {
            display.drawGlyph(20, 12, u8g2_font_iconquadpix_m_all, 0x0064);
        }
        else if (value == 1)
        {
            display.drawGlyph(20, 12, u8g2_font_iconquadpix_m_all, 0x007e);
        }
        else
        {
            display.drawGlyph(20, 12, u8g2_font_iconquadpix_m_all, 0x006c);
        }
        display.drawBox(32, 0, 2, 11);
        display.drawBox(19, 0, 1, 11);
    }

    void setMainInf()
    {
        display.setColor(2);
        display.setFont(u8g2_font_courB08_tf);
        display.drawText(17, 60, "1");
        display.drawText(46, 60, "2");
        display.drawText(75, 60, "3");
        display.drawText(104, 60, "4");
        display.drawText(119, 14, "L");
        display.drawText(119, 38, "S");
    }

    void setIcons()
    {
        display.drawBitmap(1, 13, 33, 33, DEVICE_OPERATION);
        display.setColor(2);
        display.drawGlyph(5, 10, u8g2_font_open_iconic_embedded_1x_t, 0x004a);
    }

    void setLines()
    {
        valueFrame(0);
        valueFrame(1);
        valueFrame(2);
        valueFrame(3);

        display.drawLine(0, 51, 13, 64);
        display.drawLine(0, 52, 12, 64);

        // recuadros
        display.drawFrame(0, 13, 35, 33, 3);   // maquina
        display.drawFrame(0, 0, 17, 12, 1);    // recuadro de tipo de conexion
        display.drawFrame(18, 0, 17, 12, 1);   // recuadro de pedal
        display.drawFrame(114, 0, 14, 22, 1);  // recuadro de linias
        display.drawFrame(114, 24, 14, 22, 1); // recuadro de sombras
    }

    void mainWindow(float value)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawBox(38, 1, 73, 44);
        display.drawFrame(37, 0, 75, 46, 3);

        display.setColor(0);
        display.setFont(u8g2_font_courB08_tf);
        display.drawText(60, 11, "00:00:00");
        display.drawGlyph(42, 14, u8g2_font_unifont_t_symbols, 0x23F1);

        display.setFont(u8g2_font_logisoso20_tf);
        if (value < 10)
        {
            display.setCursor(46, 40);
            display.print(String(value));
            display.drawText(93, 40, "v");
        }
        else
        {
            display.setCursor(36, 40);
            display.print(String(value));
            display.drawText(95, 40, "v");
        }
    }

    void infoWindow(int value)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawBox(38, 1, 73, 44); /////////
        display.drawFrame(37, 0, 75, 46, 3);

        display.setColor(0);
        // display.setFont(u8g2_font_courB08_tf);
        display.setFont(u8g_font_6x10);
        if (value == 0)
        {
            display.drawText(40, 11, "Ped--");
            display.drawText(74, 11, "Press");
        }
        else if (value == 1)
        {
            display.drawText(40, 11, "Ped--");
            display.drawText(74, 11, "Pulses");
        }
        else if (value == 2)
        {
            display.drawText(40, 11, "Ped--");
            display.drawText(74, 11, "Direct");
        }
        display.drawText(40, 26, "Amp--");
        display.setCursor(74, 26);
        display.print(String(0.5));
        display.drawText(99, 26, "A");

        display.drawText(40, 41, "Duty--");
        display.setCursor(76, 41);
        display.print(String(45));
        display.drawText(90, 41, "%");
    }

public:
    explicit OperationView(Display &disp) : display(disp) {}
    void show(int device_iter, int value_iter, int pedal_iter, int window_iter, int type_device_iter)
    {
        display.clear();

        display.setFontMode(1);
        display.setColor(1);

        setLines();

        // selector de tipo de pedal
        setPedalType(pedal_iter);

        // selector de valores
        setValueSelector(value_iter);

        // selector de maquinas
        setDevice(device_iter);

        // selector de tipo de maquina
        setDeviceType(type_device_iter);

        // informacion principal de interfaz
        setMainInf();

        setIcons();

        // mainWindow(9.3);
        infoWindow(1);

        display.render();
    }
};