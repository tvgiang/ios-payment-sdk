**Get Started**

Appota Payment SDK cho iOS là cách đơn giản nhất để tích hợp thanh toán
cho ứng dụng của bạn trên hệ thống Appota. SDK này cung cấp giải pháp
cho các hình thức thanh toán: SMS, thẻ cào, internet banking, Paypal và
Apple Payment.

**Các bước tích hợp SDK:**

​1. Cài đặt Appota SDK

​2. Cấu hình SDK

​3. Tích hợp

 

**1. Cài đặt Appota SDK**

**Thêm Appota.framework vào project**

Kéo thả thư mục AppotaSDK.framework và file AppotaBundle.bundle vào
project của bạn.\
 \
 Tick vào checkbox: “Copy items into destination group's folder (if
needed)”.\
 \
 Trong mục project app’s target settings, tìm mục Build phases và mở
Link Binary with Libraries. Click vào nút ‘+’ và chọn để add các
framework:

    SystemConfiguration.framework, Security.framework, CFNetwork.framework, QuaztCore.framework, MessageUI.framework, StoreKit.framework AudioToolbox.framework MobileCoreServices.framework AVFoundation.framework OpenGLES.framework CoreVideo.framework libxml2.dylib CoreMedia.framework AdSupport.framework libsqlite3.dylib

![](step1.jpg)

Trong project build settings, tìm đến mục Other Linker Flags, thêm vào 2
giá trị: -ObjC, -all\_load, -lc++.

![](step2.jpg)

Import headers vào trong source files:\
 Trong source file mà bạn cần sử dụng thư viện Appota SDK, import:

    #import <AppotaSDK/AppotaSDK.h>

**Config plist với CLIENT\_KEY**\
 \
 Thêm 1 trường AppotaClientId với giá trị là CLIENT\_ID (chi tiết về
CLIENT\_ID xem ở mục lấy ACCESS\_TOKEN).\
 Add thêm schema: Thêm 1 trường URL types kiểu Array. Tạo thêm 1 item
với URL Schemes là appotaCLIENT\_ID.\
 \
 Ví dụ nếu CLIENT\_ID = b804d6421df6ae7dbcd51469e4d8ee0005101f540 thì
schemes sẽ là appotab804d6421df6ae7dbcd51469e4d8ee0005101f540.

![](step3.jpg)

**2. Cấu hình SDK**

** Config AppotaAPI**

Các hàm của AppotaSDK được sử dụng qua AppotaPayment. Có thể gọi
AppotaPayment qua [AppotaPayment shareAPI].\
 \
 Trước khi sử dụng SDK gọi các hàm cài đặt CLIENT\_ID, CLIENT\_SECRET,
INAPP\_ID (chỉ cần gọi 1 lần duy nhất):\
 \
 Đối với ứng dụng đang ở trạng thái sandbox:\

    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.isSandBoxMode = YES;
    appotaPayment.clientID = SAND_BOX_CLIENT_ID;
    appotaPayment.clientSecret = SAND_BOX_CLIENT_SECRET;
    appotaPayment.inappKey = SAND_BOX_INAPP_API_KEY;
    appotaPayment.sandboxKey = SAND_BOX_KEY;

Đối với ứng dụng đang ở trạng thái publish:

    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.clientID = CLIENT_ID;
    appotaPayment.clientSecret = CLIENT_SECRET;
    appotaPayment.inappKey = INAPP_API_KEY;

Các tham số CLIENT\_KEY, CLIENT\_SECRET, INAPP\_API\_KEY,
SAND\_BOX\_CLIENT\_ID, SAND\_BOX\_CLIENT\_SECRET,
SAND\_BOX\_INAPP\_API\_KEY, SAND\_BOX\_KEY có thể xem tại
[https://developer.appota.com/manage-content.html](https://developer.appota.com/manage-content.html)
trong phần quản lý ứng dụng.

** Config handleOpenURL**

Trong AppDelegate của ứng dụng gọi hàm [[Appota shareAPI]
handleOpenURL:url] như sau:

    - (BOOL)application:(UIApplication *)application
    openURL:(NSURL *)url
    sourceApplication:(NSString *)sourceApplication
    annotation:(id)annotation {     return [[AppotaAPI shareAPI] handleOpenURL:url];
    }

Đối với trường hợp bạn đã sử dụng SDK khác có đặt hàm handleOpenURL tại
AppDelegate rồi (ví dụ FacebookSDK) có thể gọi [[AppotaAPI shareAPI]
handleOpenURL:url] trước khi return như sau:

    - (BOOL)application:(UIApplication *)application
    openURL:(NSURL *)url
    sourceApplication:(NSString *)sourceApplication
    annotation:(id)annotation {
       [[AppotaAPI shareAPI] handleOpenURL:url];
    return [self.facebookSDKSession handleOpenURL:url];
    }

**3. Tích hợp thanh toán**

Appota Payment SDK cung cấp lớp [AppotaPayment](AppotaPayment.html) đóng
gói toàn bộ giao diện của từng hình thức thanh toán, để tích hợp bất cứ
hình thức thanh toán nào chỉ cần gọi các hàm tương ứng được cung cấp sẵn
(tham khảo AppotaPaymentTest).

**4 - Chạy SDK Samples**

- Yêu cầu: Xcode 4.6, iOS SDK 6 trở lên.

- Mở AppotaPaymentTest.xcodeproj để chạy sample.

- Sử dụng SDK trong example:

Tất cả các API của SDK đều được gọi qua 1 hàm, ví dụ:\
 makeSMSPaymentWithAmount

Kết quả trả về trong block của hàm qua Appota AppotaPaymentHandler (tham
khảo AppotaPayment.h trong SDK). Giá trị của kết quả có thể xác định qua
giá trị của NSDictionary, AppotaPaymentState và NSError trả về qua
AppotaPaymentHandler. (Các state của AppotaPaymentState tham khảo
AppotaPayment.h trong SDK)

Dev cần đặt code xử lý kết quả của payment trong block của payment API
ví dụ:

    [appotaPayment makeSMSPaymentWithAmount:500 withState:@"" withTarget:@"" withNoticeUrl:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
    // Xử lý kết quả của payment ở đây
        [self handleSMSPaymentResultDict:apiDict withPaymentState:status];
    }];

 ![](sample1.png) ![](sample2.png) ![](sample3.png) ![](sample4.png)
