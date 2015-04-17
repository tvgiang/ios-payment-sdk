Other languages: [English](README_EN.md) | [Chinese](README_CN.md)

**Get Started**

Appota Payment SDK cho iOS là cách đơn giản nhất để tích hợp thanh toán
cho ứng dụng của bạn trên hệ thống Appota. SDK này cung cấp giải pháp
cho các hình thức thanh toán: SMS, thẻ cào, internet banking, Paypal và
Apple Payment. Chi tiết về phương thức kết nối xin liên hệ sale@appota.com.

**Các bước tích hợp SDK:**

​1. Cài đặt Appota SDK

​2. Cấu hình SDK

​3. Tích hợp

 

**1. Cài đặt Appota SDK**

**Thêm Appota.framework vào project**

Kéo thả thư mục AppotaSDK.framework và file AppotaBundle.bundle vào
project của bạn.

Tick vào checkbox: “Copy items into destination group's folder (if needed)”.
 
Trong mục project app’s target settings, tìm mục Build phases và mở
Link Binary with Libraries. Click vào nút ‘+’ và chọn để add các framework:

```
SystemConfiguration.framework, Security.framework, CFNetwork.framework, QuaztCore.framework,
MessageUI.framework, StoreKit.framework, AudioToolbox.framework, MobileCoreServices.framework,
AVFoundation.framework, OpenGLES.framework, CoreVideo.framework, libxml2.dylib, CoreMedia.framework,
AdSupport.framework, libsqlite3.dylib
```

![](docs/vn/step1.jpg)

Trong project build settings, tìm đến mục Other Linker Flags, thêm vào 2 giá trị: -ObjC, -all_load, -lc++.

![](docs/vn/step2.jpg)

Import headers vào trong source files:

Trong source file mà bạn cần sử dụng thư viện Appota SDK, import:

``` objective-c
#import <AppotaSDK/AppotaSDK.h>
```

**Config plist với CLIENT_KEY**
 
Thêm 1 trường AppotaClientId với giá trị là CLIENT_ID (chi tiết về CLIENT_ID xem ở mục lấy ACCESS_TOKEN).
Add thêm schema: Thêm 1 trường URL types kiểu Array. Tạo thêm 1 item với URL Schemes là appotaCLIENT_ID.

Ví dụ nếu CLIENT_ID = b804d6421df6ae7dbcd51469e4d8ee0005101f540 thì schemes sẽ là appotab804d6421df6ae7dbcd51469e4d8ee0005101f540.

![](docs/vn/step3.jpg)

**2. Cấu hình SDK**

** Config AppotaAPI**

Các hàm của AppotaSDK được sử dụng qua AppotaPayment. Có thể gọi
AppotaPayment qua [AppotaPayment shareAPI].

Trước khi sử dụng SDK gọi các hàm cài đặt CLIENT_ID, CLIENT_SECRET,INAPP_ID (chỉ cần gọi 1 lần duy nhất):

Đối với ứng dụng đang ở trạng thái sandbox:

``` objective-c
AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
appotaPayment.isSandBoxMode = YES;
appotaPayment.clientID = SAND_BOX_CLIENT_ID;
appotaPayment.clientSecret = SAND_BOX_CLIENT_SECRET;
appotaPayment.inappKey = SAND_BOX_INAPP_API_KEY;
appotaPayment.sandboxKey = SAND_BOX_KEY;
```

Đối với ứng dụng đang ở trạng thái publish:

``` objective-c
AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
appotaPayment.clientID = CLIENT_ID;
appotaPayment.clientSecret = CLIENT_SECRET;
appotaPayment.inappKey = INAPP_API_KEY;
```

Các tham số CLIENT_KEY, CLIENT_SECRET, INAPP_API_KEY, SAND_BOX_CLIENT_ID, SAND_BOX_CLIENT_SECRET, SAND_BOX_INAPP_API_KEY, SAND_BOX_KEY có thể xem tại
[https://developer.appota.com/manage-content.html](https://developer.appota.com/manage-content.html) trong phần quản lý ứng dụng.

** Config handleOpenURL**

Trong AppDelegate của ứng dụng gọi hàm [[Appota shareAPI]
handleOpenURL:url] như sau:

``` objective-c
- (BOOL)application:(UIApplication *)application
openURL:(NSURL *)url
sourceApplication:(NSString *)sourceApplication
annotation:(id)annotation {     
    return [[AppotaAPI shareAPI] handleOpenURL:url];
}
````

Đối với trường hợp bạn đã sử dụng SDK khác có đặt hàm handleOpenURL tại
AppDelegate rồi (ví dụ FacebookSDK) có thể gọi [[AppotaAPI shareAPI]
handleOpenURL:url] trước khi return như sau:

``` objective-c
- (BOOL)application:(UIApplication *)application
openURL:(NSURL *)url
sourceApplication:(NSString *)sourceApplication
annotation:(id)annotation {
    [[AppotaAPI shareAPI] handleOpenURL:url];
    return [self.facebookSDKSession handleOpenURL:url];
}
```

**3. Tích hợp thanh toán**

Appota Payment SDK cung cấp lớp [AppotaPayment](docs/vn/AppotaPayment.md) đóng
gói toàn bộ giao diện của từng hình thức thanh toán, để tích hợp bất cứ
hình thức thanh toán nào chỉ cần gọi các hàm tương ứng được cung cấp sẵn
(tham khảo AppotaPaymentTest).

**4 - Chạy SDK Samples**

- Yêu cầu: Xcode 4.6, iOS SDK 6 trở lên.

- Mở AppotaPaymentTest.xcodeproj để chạy sample.

- Sử dụng SDK trong example:

Tất cả các API của SDK đều được gọi qua 1 hàm, ví dụ: makeSMSPaymentWithAmount

Kết quả trả về trong block của hàm qua Appota AppotaPaymentHandler (tham
khảo AppotaPayment.h trong SDK). Giá trị của kết quả có thể xác định qua
giá trị của NSDictionary, AppotaPaymentState và NSError trả về qua
AppotaPaymentHandler. (Các state của AppotaPaymentState tham khảo
AppotaPayment.h trong SDK)

Dev cần đặt code xử lý kết quả của payment trong block của payment API
ví dụ:

``` objective-c
[appotaPayment makeSMSPaymentWithAmount:500 withState:@"" withTarget:@"" withNoticeUrl:@"" 
withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
    // Xử lý kết quả của payment ở đây
    [self handleSMSPaymentResultDict:apiDict withPaymentState:status];
}];
```

 ![](docs/vn/sample1.png)&nbsp;![](docs/vn/sample2.png)&nbsp;![](docs/vn/sample3.png)&nbsp;
