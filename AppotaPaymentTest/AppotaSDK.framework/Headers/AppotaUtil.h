//
//  AppotaUtil.h
//  AppotaSDK
//
//  Created by tuent on 10/1/13.
//
//

#import <Foundation/Foundation.h>

@class AppotaPaymentController;

@interface AppotaUtil : NSObject
+ (NSBundle *)frameworkBundle;
+(UIImage *)imageWithNamed:(NSString *)imgName ofType:(NSString *)extension;
+ (UIImage*) imageNamed:(NSString*) imageName;
+ (UIViewController *) firstAvailableUIViewController:(UIView*) v;
+ (CGSize) getWindowSize;
+ (NSArray*) getListSMSOptionWithSMSListAmount:(NSArray*) listSMSAmount
                          withSMSStructureDict:(NSDictionary*) smsDict;
+(void) alertWithTitle:(NSString*) alertTitle
           withMessage:(NSString*) alertMessage;
+ (UIView*) getSMSViewWithText:(NSString*) smsText
                    withRecpit:(NSString*) smsRecpt
                withController:(AppotaPaymentController*) controller
                     withFrame:(CGRect) viewFrame;
+ (NSArray*) getArrayOfDescriptionFromString:(NSString*) descriptionString;

+ (void) setLanguageForView:(UIView*) v;
@end
