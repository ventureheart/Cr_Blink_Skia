echo "Setting up port forward"
adb forward "tcp:5039" "tcp:5039"

# Kill all previous instances of gdbserver and the app to rid all port overriding errors.
echo "Killing any running Skia processes."
adb shell ps | grep gdbserver | awk '{print $2}' | xargs adb shell kill
adb shell ps | grep bench | awk '{print $2}' | xargs adb shell kill

# Starting up gdbserver in android shell
echo "Starting gdbserver with command: bench"
adb push ./gdbserver /data/local/tmp
adb shell /data/local/tmp/gdbserver :5039 /data/local/tmp/skia_launcher bench &

# Wait for gdbserver
sleep 2

# variables that must match those in gdb_server
#GDB_SYS_DIR=/home/venture/Graphics/skia/skiaOnAndroid/4Android/gdb/gdb_android/system/lib
GDB_TMP_DIR=./android_gdb_tmp
#GDB_TMP_DIR=/home/venture/Graphics/skia/skiaOnAndroid/4Android/gdb/gdb_android/data/local/tmp
APP_NAME=bench
PORT=5039

# Set up gdb commands
GDBSETUP=$GDB_TMP_DIR/gdb.setup
echo "file $GDB_TMP_DIR/skia_launcher" >> $GDBSETUP
echo "target remote :$PORT" >> $GDBSETUP
#echo "set sysroot $GDB_SYS_DIR" >> $GDBSETUP
echo "set solib-absolute-prefix $GDB_TMP_DIR" >> $GDBSETUP
echo "set solib-search-path $GDB_TMP_DIR" >> $GDBSETUP

# The apps shared library symbols are not loaded by default so we load them here
# echo "break launch_app" >> $GDBSETUP
# echo "break SkCanvas::drawRect" >> $GDBSETUP
# echo "break main" >> $GDBSETUP
echo "break external/skia/launcher/skia_launcher.cpp:26" >> $GDBSETUP
echo "continue" >> $GDBSETUP
echo "sharedLibrary $APP_NAME" >> $GDBSETUP

# Launch gdb client
echo "Entering gdb client shell"
  ./i686-linux-android-gdb -x $GDBSETUP
  #./x86_64-linux-android-gdb -x $GDBSETUP
  #$ANDROID_TOOLCHAIN/arm-linux-androideabi-gdb -x $GDBSETUP

# Clean up
#rm -rf $GDB_TMP_DIR
rm -rf $GDBSETUP
