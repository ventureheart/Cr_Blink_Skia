echo "Setting up port forward"
adb forward "tcp:5039" "tcp:5039"

# Kill all previous instances of gdbserver and the app to rid all port overriding errors.
echo "Killing any running Skia processes."
adb shell ps | grep gdbserver | awk '{print $2}' | xargs adb shell kill
adb shell ps | grep bench | awk '{print $2}' | xargs adb shell kill

# Starting up gdbserver in android shell
echo "Starting gdbserver with command: bench"
adb shell /data/local/tmp/gdbserver :5039 /data/local/tmp/skia_launcher bench &

