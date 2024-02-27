**AsyncMessageBox - A Qt Solution for Non-Blocking Message Boxes**

**Problem:**

Qt's standard message boxes (QMessageBox) have limitations when used within threads:

* They cannot be directly created or shown from a thread other than the main UI thread.
* Obtaining the user's response from the message box within a thread is challenging.

**Solution:**

The AsyncMessageBox class provides a solution for using message boxes seamlessly within multi-threaded Qt applications. It allows you to:

* Create and show message boxes from any thread.
* Handle user responses asynchronously within your thread using Qt signals.

**Key Features**

* **Asynchronous operation:** Message boxes are displayed without interrupting the main thread's execution.
* **Signal-based result handling:**  Use Qt signals to get notified when the user interacts with the message box, allowing you to react accordingly.
* **Familiar API:**  Designed to resemble the standard `QMessageBox` interface for ease of use.

**How to Use**

1. Include the `AsyncMessageBox` header file in your project.
2. Create an instance of `AsyncMessageBox`.
3. Set the message box properties (title, text, buttons, etc.)
4. Use ShowAsyncMessageBox() to show messagebox asynchronously. 
5. Use WaitForDone() to get result, if you need the messagebox result.

**Example**

```c++
#include "AsyncMessageBox.h"

// ...

amsg->setText("Erorr");
amsg->setDetailedText("This is my error message from thread.");
amsg->ShowAsyncMessageBox();
auto r = amsg->WaitForDone();
