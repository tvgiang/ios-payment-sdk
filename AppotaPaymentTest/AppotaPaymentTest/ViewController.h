//
//  ViewController.h
//  AppotaPaymentTest
//
//  Created by tuent on 10/9/13.
//
//

#import <UIKit/UIKit.h>
#define CLIENT_ID           @"0f25ad0ef73a1ca4188415be07511267052cf9170"
#define CLIENT_SECRET       @"55611b743ad380ded2e70caee6e334d3052cf9170"
#define INAPP_API_KEY       @"de5f5212f4537e42c4600e0bec6230f2052cf9170"
#define SANDBOX_CLIENT_ID @"SANDBOX_CLIENT_ID"
#define SANDBOX_CLIENT_SECRET @"SANDBOX_CLIENT_SECRET"
#define SANDBOX_INAPP_API_KEY @"SANDBOX_INAPP_API_KEY"

@interface ViewController : UIViewController
- (IBAction)makeApplePaymentWithList:(id)sender;
- (IBAction)makeApplePayment:(id)sender;
- (IBAction)showBankWithListAmount:(id)sender;
- (IBAction)showBankWithAmount:(id)sender;

- (IBAction)showBankWithInputAmount:(id)sender;


- (IBAction)showPaypalWithInputAmount:(id)sender;

- (IBAction)showPaypalWithListAmount:(id)sender;
- (IBAction)showPaypalWithAmount:(id)sender;
- (IBAction)showCardWithListVendor:(id)sender;
- (IBAction)showSMSWithAmount:(id)sender;
- (IBAction)showSMSWithState:(id)sender;
- (IBAction)showSMSWithListAmount:(id)sender;
@end
