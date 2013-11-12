**Get Started**

Appota Payment SDK for iOS is the simplest way to integrate payment for
your application on Appota system. This SDK provides solutions for
payment methods such as: SMS, Card, Internet Banking, Paypal and Apple
Payment.

**Steps to integrate SDK:**

​1. Setup Appota SDK

​2. Config SDK

​3. Integrate SDK

 

**1. Setup Appota SDK**

**Import Appota.framework into project**

Drag and drop AppotaSDK.framework and AppotaBundle.bundle into your
project.\
 \
 Tick on checkbox: “Copy items into destination group's folder (if
needed)”.\
 \
 In Project app’s target settings section, find [Build phases] and open
Link Binary with Libraries. Click on ‘+’ button and add these
frameworks:

    SystemConfiguration.framework, Security.framework, CFNetwork.framework, QuaztCore.framework, MessageUI.framework, StoreKit.framework AudioToolbox.framework MobileCoreServices.framework AVFoundation.framework OpenGLES.framework CoreVideo.framework libxml2.dylib CoreMedia.framework AdSupport.framework libsqlite3.dylib

![](step1.jpg)

In project build settings section, find Other Linker Flags, add two
values: -ObjC và -all\_load.

![](step2.jpg)

Import headers into source files:\
 In source file you need to use Appota SDK Library, import:

    #import <AppotaSDK/AppotaSDK.h>

**Config plist with CLIENT\_KEY**\
\
Add 1 string AppotaClientId with the value is CLIENT\_ID (details about
CLIENT\_ID are in section of getting ACCESS\_TOKEN)\
 Add more schema: Add 1 string URL Array types. Creat 1 item more with
URL Schemes is appotaCLIENT\_ID.\
\
For example: If CLIENT\_ID = b804d6421df6ae7dbcd51469e4d8ee0005101f540,
schemes will be appotab804d6421df6ae7dbcd51469e4d8ee0005101f540.

![](step3.jpg)

**2. Config SDK**

** Config AppotaAPI**

Functions of AppotaSDK used via AppotaPayment. You can call
AppotaPayment via [AppotaPayment shareAPI].\
 \
 Before using SDK to call functions setting up CLIENT\_ID,
CLIENT\_SECRET, INAPP\_ID (just call only one time):\
 \
 For application in sandbox status:

AppotaPayment \*appotaPayment = [AppotaPayment shareAPI];\
 appotaPayment.isSandBoxMode = YES;\
 appotaPayment.clientID = SAND\_BOX\_CLIENT\_ID;\
 appotaPayment.clientSecret = SAND\_BOX\_CLIENT\_SECRET;\
 appotaPayment.inappKey = SAND\_BOX\_INAPP\_API\_KEY;\
 appotaPayment.sandboxKey = SAND\_BOX\_KEY;\

For application in publish status:

    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.clientID = CLIENT_ID;
    appotaPayment.clientSecret = CLIENT_SECRET;
    appotaPayment.inappKey = INAPP_API_KEY;

Parameters such as CLIENT\_KEY, CLIENT\_SECRET, INAPP\_API\_KEY,
SAND\_BOX\_CLIENT\_ID, SAND\_BOX\_CLIENT\_SECRET,
SAND\_BOX\_INAPP\_API\_KEY, SAND\_BOX\_KEY can be seen on
[https://developer.appota.com/manage-content.html](https://developer.appota.com/manage-content.html)
(in section of application management).

** Config handleOpenURL**

In AppDelegate of application call function [[Appota shareAPI]
handleOpenURL:url] as follow:

    - (BOOL)application:(UIApplication *)application
    openURL:(NSURL *)url
    sourceApplication:(NSString *)sourceApplication
    annotation:(id)annotation {     return [[AppotaAPI shareAPI] handleOpenURL:url];
    }

In case that you used another SDK setting handleOpenURL function in
AppDelegate (for example FacebookSDK), you can call [[AppotaAPI
shareAPI] handleOpenURL:url] before returning as follow:

    - (BOOL)application:(UIApplication *)application
    openURL:(NSURL *)url
    sourceApplication:(NSString *)sourceApplication
    annotation:(id)annotation {
       [[AppotaAPI shareAPI] handleOpenURL:url];
    return [self.facebookSDKSession handleOpenURL:url];
    }

**3. Integrate SDK**

Appota Payment SDK provides class [AppotaPayment](AppotaPayment.html)
packaging entire interface of each payment method. To integrate any
payment methods, you just call respective functions given (refer to
AppotaPaymentTest).

**4 - Run SDK Samples**

- Requirement: Xcode 4.6, iOS SDK 6 or more.

- Open AppotaPaymentTest.xcodeproj to run sample.

- Use SDK in example:

All APIs of SDK are called via 1 function, for example:\
 makeSMSPaymentWithAmount

Results returned in block of function via AppotaPaymentHandler (refer to
AppotaPayment.h in SDK). Value of result can be identified via value of
NSDictionary, AppotaPaymentState and NSError are returned via
AppotaPaymentHandler. (States of AppotaPaymentState are referred to 
AppotaPayment.h in SDK)

Dev need to set code to handle results of payment in payment's block,
for example:

    [appotaPayment makeSMSPaymentWithAmount:500 withState:@"" withTarget:@"" withNoticeUrl:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
    // Process payment result here
        [self handleSMSPaymentResultDict:apiDict withPaymentState:status];
    }];

 ![](sample1.png) ![](sample2.png) ![](sample3.png) ![](sample4.png)
