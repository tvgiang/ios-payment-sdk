//
//  ViewController.h
//  AppotaPaymentTest
//
//  Created by tuent on 10/9/13.
//
//

#import <UIKit/UIKit.h>
#define CLIENT_ID           @"ba3a3c9bc5542e0a71dcda804b2dbf09052c23557"
#define CLIENT_SECRET       @"12b54112775d52e8ba16e7142413ee95052c23557"
#define INAPP_API_KEY       @"97b13c7047b0af17116051bff3571bfa052c23557"
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
