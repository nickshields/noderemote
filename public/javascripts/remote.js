$(document).ready(function() {
	$('.remote-round').click(function() {
		var command = $(this).attr("value");
		var remote_configure = false;
		if ( $('input[name="test"]').is(':checked') ) {
			    remote_configure = true;
			}
		$.post('/tvCommand', {"command":command, "configure":remote_configure});
	});
	$('.remote-square').click(function() {
		var command = $(this).attr("value");
		var remote_configure = false;
		if ( $('input[name="test"]').is(':checked') ) {
			    remote_configure = true;
			}
		$.post('/tvCommand', {"command":command, "configure":remote_configure});
	});
	$('.remote-round-sm').click(function() {
		var command = $(this).attr("value");
		var remote_configure = false;
		if ( $('input[name="test"]').is(':checked') ) {
			    remote_configure = true;
			}
		$.post('/tvCommand', {"command":command, "configure":remote_configure});
	});

});