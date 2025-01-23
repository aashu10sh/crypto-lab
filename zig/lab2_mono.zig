const std = @import("std");

const Message = struct {
    message: []u8,
};

const MAX: u16 = 300;

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    defer _ = gpa.deinit();

    const map = std.meta.ComptimeStringMap(u8, .{
        .{ 'a', 'm' },
        .{ 'b', 'o' },
        .{ 'c', 'q' },
        .{ 'd', 's' },
        .{ 'e', 'z' },
        .{ 'f', 'x' },
        .{ 'g', 'h' },
        .{ 'h', 'k' },
        .{ 'i', 'l' },
        .{ 'j', 'p' },
        .{ 'k', 'n' },
        .{ 'l', 'u' },
        .{ 'm', 'v' },
        .{ 'n', 'y' },
        .{ 'o', 'w' },
        .{ 'p', 'r' },
        .{ 'q', 't' },
        .{ 'r', 'a' },
        .{ 's', 'j' },
        .{ 't', 'g' },
        .{ 'u', 'd' },
        .{ 'v', 'i' },
        .{ 'w', 'e' },
        .{ 'x', 'f' },
        .{ 'y', 'c' },
        .{ 'z', 'b' },
    });

    const stdout = std.io.getStdOut().writer();
    try stdout.print("enter your message: ", .{});

    var buffer: [MAX]u8 = undefined;
    const stdin = std.io.getStdIn().reader();
    const input = try stdin.readUntilDelimiter(&buffer, '\n');

    var encrypted = std.ArrayList(u8).init(allocator);
    defer encrypted.deinit();

    for (input) |char| {
        if (map.get(char)) |new_char| {
            try encrypted.append(new_char);
        } else {
            try stdout.print("error: key not in map, please use only lowercase characters\n", .{});
            return error.InvalidInput;
        }
    }

    try stdout.print("encrypted: {s}\n", .{encrypted.items});
}
