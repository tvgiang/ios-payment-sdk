//
//  AppotaAdsSDK
//  AppotaAdsSDK
//  Created by Appota's Mac on 1/7/13.
//  Copyright (c) 2013 Appota's Mac. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////
// Summary
// Class AppotaAdsSDK bao gồm các function được gọi để khởi tạo device cho quảng cáo và active khi đạt mức quảng cáo yêu cầu
#import "AppotaAdsNetworkEngine.h"

@class AppotaAdsSDK;

typedef void (^AppotaAdsHandler)(AppotaAdsSDK *adsSDK, NSString* apiResult, NSError *error);
typedef void (^FetcherBlock)(NSString *twitPicURL);
typedef void (^FetcherArrayBlock)(NSMutableArray *list);
typedef void (^FetcherDictionary)(NSDictionary *dict);
typedef void (^BOOLBlock)(BOOL b);

@interface AppotaAdsSDK : AppotaAdsNetworkEngine
{
    AppotaAdsHandler adsHandler;
}

// Singleton function cho SDK
+ (id)sharedAppotaAdsSDK;

// Khởi tạo device thực hiện quảng cáo
// Handler trả về kết quả gọi api và lỗi nếu có
- (void) initDeviceAdsWithHandler:(AppotaAdsHandler) handler;

// Xác nhận device đã hoàn thành mức quảng cáo yêu cầu
// Gọi hàm này để xác nhận device đã hoàn thành mức quảng cáo yêu cầu
- (void) activeDeviceAdsWithHandler:(AppotaAdsHandler) handler;
@end
