//
// SHPKeyboardAwareness
// SHPKeyboardEvent.h
//
// Copyright (c) 2014-2015 SHAPE A/S. All rights reserved.
//

typedef NS_ENUM(NSUInteger, SHPKeyboardEventType) {
    SHPKeyboardEventTypeShow,
    SHPKeyboardEventTypeHide,
};

#import <Foundation/Foundation.h>

@interface SHPKeyboardEvent : NSObject

/// The view that conflicts with the keyboard
@property (nonatomic, readonly) UIView *conflictingView;

/// The offset required to clear conflictingView of the keyboard
@property (nonatomic, readonly) CGFloat requiredViewOffset;

/// The frame of the part of the screen, not taken up by a keyboard
@property (nonatomic, readonly) CGRect visibleScreenArea;

/// The frame of the keyboard, when animation completes
@property (nonatomic, readonly) CGRect keyboardFrame;

/// The duration of the keyboard animation
@property (nonatomic, readonly) CGFloat keyboardAnimationDuration;

/// The curve of the keyboard animation
@property (nonatomic, readonly) UIViewAnimationCurve keyboardAnimationCurve;

/// The curve of the keyboard animation, represented as a UIViewAnimationOptions type for use with the UIView block based animation methods
@property (nonatomic, readonly) UIViewAnimationOptions keyboardAnimationOptionCurve;

/// Indicates if the keyboard event is a show or hide event
@property (nonatomic, readonly) SHPKeyboardEventType keyboardEventType;

/// Property where user can save original content offset to be applied once keyboard hides. Will be preserved between show/hide events.
@property (nonatomic, assign) CGFloat originalOffset;

/// Convenience method for animating with pace of the keyboard. Should be called when the keyboard event is fired.
- (void) animateWithKeyboard:(void (^)(void))animations;

/// Convenience method for animating with pace of the keyboard with optional completion block. Should be called when the keyboard event is fired.
- (void) animateWithKeyboard:(void (^)(void))animations completion: (void (^)(BOOL finished))completion;

@end
