//
//  AppotaTopupView.h
//  AppotaSDK
//
//  Created by ToanDK's Mac on 5/7/13.
//
//

#import <UIKit/UIKit.h>
#import "AppotaPayment.h"
#import "AppotaDialog.h"

@interface AppotaTopupView : AppotaDialog<UIWebViewDelegate> {
    NSString *topupLink;
    AppotaTopUpWebHandler handler;
    UIButton *logoutBtn;
}
@property (nonatomic, strong) NSString *callbackURI;

-(void)loadWebURL:(NSString *)link withCallbackURI:(NSString *)callbackUri
withCompletionBlock:(AppotaTopUpWebHandler)completeBlock;
-(void)addCompletionHandler:(AppotaTopUpWebHandler)block;
- (void) reloadWebView;
@end
