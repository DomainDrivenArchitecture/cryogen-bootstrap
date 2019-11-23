<div id="prev-next">
    {% if post.prev-uri %}
    <a class="left" href="{{post.prev-uri}}">&laquo; Vor</a>
    {% endif %}
    {% if post.next-uri %}
    <a class="right" href="{{post.next-uri}}">Weiter &raquo;</a>
    {% endif %}
</div>