// Problem Statement: "Browser History Management"
// You are tasked with implementing a simplified browser history management system. This system should allow users to navigate between previously visited pages, and also add new pages to their history. The system needs to efficiently handle both "back" and "forward" navigation, as well as adding new pages, while maintaining a limited history size.
// Requirements:
//  When a user visits a new page, it should be added to the current history. If there are any "forward" pages available (i.e., pages visited after the current page in the history), they should be cleared, as visiting a new page effectively creates a new branch in the history.
//  Users should be able to navigate to the previous page in their history. If there's no previous page, they remain on the current page.
//  Users should be able to navigate to a page they previously went "back" from. If there's no page to go forward to, they remain on the current page.
//  The browser history should have a maximum capacity. If adding a new page exceeds this capacity, the oldest page in the history should be automatically removed to make space.
// Input:
// A sequence of operations:
// visit(url): Adds url to the history.
// back(steps): Navigates back by steps pages.
// forward(steps): Navigates forward by steps pages.
// Output:
// For each visit, back, or forward operation, output the URL of the page the user is currently on after the operation.
