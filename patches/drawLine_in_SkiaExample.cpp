#include "SkExample.h"

#include "SkDevice.h"

class HelloTutorial : public SkExample {
    public:
        //HelloTutorial(void* hWnd, int argc, char** argv)
        //    : INHERITED(hWnd, argc, argv)
        HelloTutorial(SkExampleWindow* window) : SkExample(window)
        {
            // Another option is software rendering:
            // setupBackend(kRaster_DeviceType);
            fWindow->setupBackend(SkExampleWindow::kGPU_DeviceType);
        }

    protected:
        virtual void draw(SkCanvas* canvas) SK_OVERRIDE {
            // Clear background
            canvas->drawColor(SK_ColorWHITE);

            SkPaint paint;
            // Draw a message with a nice black paint.
            paint.setFlags(SkPaint::kAntiAlias_Flag);
            paint.setColor(SK_ColorBLACK);
            paint.setStyle(SkPaint::kStroke_Style);
            paint.setStrokeWidth(SkIntToScalar(5));
            //paint.setStrokeJoin(SkPaint::kBevel_Join);
            //paint.setTextSize(SkIntToScalar(20));

            canvas->save();
            //canvas->rotate(45);
            //canvas->translate(SkIntToScalar(200), SkIntToScalar(0));

            //static const char message[] = "Hello Tutorial!";
            // Translate and rotate
            //canvas->translate(SkIntToScalar(50), SkIntToScalar(100));

            // Draw the text:
           /* canvas->drawLine(50, 50, 100, 50, paint);
            canvas->drawLine(100, 50, 100, 100, paint);
            canvas->drawLine(100, 100, 100, 50, paint);
            canvas->flush();*/

            /* SkPath path;
            path.moveTo(200, 200);
            path.lineTo(200, 300);
            //path.arcTo(200, 300, 200, 400, 50);
            path.lineTo(300, 300);
            path.lineTo(300, 200);
            path.close();
            path.dump();
            canvas->drawPath(path, paint);
            //path.dump();
            canvas->flush(); */
            //path.dump();
            
            SkPath path;
            path.moveTo(100, 100);
            path.lineTo(50, 150);
            //path.arcTo(200, 300, 200, 400, 50);
            path.lineTo(100, 200);
            path.lineTo(150, 150);
            path.close();
            canvas->drawPath(path, paint);
            
            //SkPath path;
            path.moveTo(100, 100);
            path.lineTo(50, 150);
            //path.arcTo(200, 300, 200, 400, 50);
            path.lineTo(100, 200);
            path.lineTo(150, 150);
           // path.close();
            canvas->drawPath(path, paint);
            canvas->flush(); 
            //canvas->drawText(message, strlen(message), SkIntToScalar(0), SkIntToScalar(0), paint);
		

            /* SkPath path;
            SkRect r = { 100, 100, 200, 200 };
            path.addRect(r);
            canvas->drawPath(path, paint);
            canvas->flush(); */

            //canvas->translate(SkIntToScalar(50), SkIntToScalar(100));
            //SkRect r = { 100.5, 100.5, 200.5, 200.5 };
           /* SkRect r = { 100, 100, 200, 200};
            //SkRect r = { 100, 100, 100, 200 };       // this rect will be (100, 100), (50, 150), (100, 200), (150, 150)
            canvas->drawRect(r, paint);
            canvas->flush(); */


            canvas->restore();
            // If you ever want to do animation. Use the inval method to trigger a redraw.
            // this->inval(NULL);

            //INHERITED::draw(canvas);
            //this->fWindow->inval(NULL);
        }

    private:
        typedef SkExample INHERITED;
};

static SkExample* MyFactory(SkExampleWindow *window) {
    return new HelloTutorial(window);
}

//SkExample::SetExample<HelloTutorial> reg("Hello Tutorial");
SkExample::Registry drawline(MyFactory);
